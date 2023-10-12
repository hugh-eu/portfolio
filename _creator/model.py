import os
import cv2
import time
import random
import numpy as np
import tensorflow as tf


class Model:
    def __init__(self, model_dir, backup_model_dir):
        self.sequence_shape = (None, None, None, 3)
        self.sequence_generator = None
        self.sequence_discriminator = None
        self.sequence_gan = None
        self.sequence_generator_model_path = f'{model_dir}/sequence_generator_model.h5'
        self.sequence_discriminator_model_path = f'{model_dir}/sequence_discriminator_model.h5'
        self.sequence_gan_model_path = f'{model_dir}/sequence_gan_model.h5'
        self.backup_sequence_generator_model_path = f'{backup_model_dir}/sequence_generator_model.h5'
        self.backup_sequence_discriminator_model_path = f'{backup_model_dir}/sequence_discriminator_model.h5'
        self.backup_sequence_gan_model_path = f'{backup_model_dir}/sequence_gan_model.h5'
        self.build_or_load_models()


    def build_sequence_generator(self):
        ref_frame_input = tf.keras.layers.Input(shape=self.sequence_shape[1:])

        ref_frame_input_sequence = tf.expand_dims(ref_frame_input, axis=1)
        ref_frame_input_sequence_shape = tf.shape(ref_frame_input_sequence)

        noise_sequence = tf.clip_by_value(tf.random.normal(shape=ref_frame_input_sequence_shape), -1, 1)
        noise_sequence = tf.tile(noise_sequence, [1, 4, 1, 1, 1])

        ref_sequence = tf.keras.layers.Concatenate(axis=1)([ref_frame_input_sequence, noise_sequence])

        x = tf.keras.layers.ConvLSTM2D(filters=16, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(ref_sequence)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=32, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=64, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=128, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=256, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=512, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=512, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=256, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=128, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=64, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=32, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        x = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=16, kernel_size=(3, 3), strides=(2, 2), padding='same', use_bias=False))(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.ReLU())(x)

        generator_output = tf.keras.layers.TimeDistributed(tf.keras.layers.Conv2DTranspose(filters=self.sequence_shape[-1], kernel_size=(3, 3), padding='same', activation='tanh'))(x)

        return tf.keras.Model(inputs=[ref_frame_input], outputs=generator_output, name='sequence_generator')


    def build_sequence_discriminator(self):
        sequence_input = tf.keras.layers.Input(shape=self.sequence_shape)

        x = tf.keras.layers.ConvLSTM2D(filters=16, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(sequence_input)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=32, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=64, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=128, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=256, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        x = tf.keras.layers.ConvLSTM2D(filters=512, kernel_size=(3, 3), strides=(2, 2), padding='same', activation=None, use_bias=False, return_sequences=True)(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LayerNormalization())(x)
        x = tf.keras.layers.TimeDistributed(tf.keras.layers.LeakyReLU(0.2))(x)

        discriminator_output = tf.keras.layers.ConvLSTM2D(filters=1, kernel_size=(3, 3), padding='same', activation='sigmoid', return_sequences=True)(x)

        return tf.keras.Model(inputs=[sequence_input], outputs=discriminator_output, name='sequence_discriminator')


    def build_sequence_gan(self):
        self.sequence_discriminator.trainable = False

        ref_frame_input = tf.keras.layers.Input(shape=self.sequence_shape[1:])
        real_sequence_input = tf.keras.layers.Input(shape=self.sequence_shape)

        generated_sequence = self.sequence_generator([ref_frame_input])

        discriminator_output = self.sequence_discriminator([generated_sequence])

        bce_loss = tf.reduce_mean(tf.keras.losses.binary_crossentropy(tf.ones_like(discriminator_output), discriminator_output))
        l1_loss = tf.reduce_mean(tf.keras.losses.mean_absolute_error(real_sequence_input, generated_sequence))
        total_loss = (bce_loss * 1) + (l1_loss * 10)

        return tf.keras.Model(inputs=[ref_frame_input, real_sequence_input], outputs=total_loss, name='sequence_gan')


    def build_or_load_models(self):
        try:
            if os.path.exists(self.sequence_generator_model_path):
                self.sequence_generator = tf.keras.models.load_model(self.sequence_generator_model_path, custom_objects={'<lambda>': lambda _, total_loss: total_loss})
            else:
                self.sequence_generator = self.build_sequence_generator()
            if os.path.exists(self.sequence_discriminator_model_path):
                self.sequence_discriminator = tf.keras.models.load_model(self.sequence_discriminator_model_path, custom_objects={'<lambda>': lambda _, total_loss: total_loss})
            else:
                self.sequence_discriminator = self.build_sequence_discriminator()
                self.sequence_discriminator.compile(loss=tf.keras.losses.BinaryCrossentropy(), optimizer=tf.keras.optimizers.Adam(learning_rate=0.0002, beta_1=0.5, beta_2=0.999))
            if os.path.exists(self.sequence_gan_model_path):
                self.sequence_gan = tf.keras.models.load_model(self.sequence_gan_model_path, custom_objects={'<lambda>': lambda _, total_loss: total_loss})
            else:
                self.sequence_gan = self.build_sequence_gan()
                self.sequence_gan.compile(loss=lambda _, total_loss: total_loss, optimizer=tf.keras.optimizers.Adam(learning_rate=0.0002, beta_1=0.5, beta_2=0.999))
            self.save_model()
        except Exception as e:
            print(e)
            time.sleep(3)
            self.sequence_generator = None
            self.sequence_discriminator = None
            self.sequence_gan = None


    def save_model(self):
        self.sequence_generator.save(self.sequence_generator_model_path, include_optimizer=True, overwrite=True)
        self.sequence_discriminator.save(self.sequence_discriminator_model_path, include_optimizer=True, overwrite=True)
        self.sequence_gan.save(self.sequence_gan_model_path, include_optimizer=True, overwrite=True)
        self.sequence_generator.save(self.backup_sequence_generator_model_path, include_optimizer=True, overwrite=True)
        self.sequence_discriminator.save(self.backup_sequence_discriminator_model_path, include_optimizer=True, overwrite=True)
        self.sequence_gan.save(self.backup_sequence_gan_model_path, include_optimizer=True, overwrite=True)


    def get_sequence_dataset(self, batch_size, file_paths):
        def generator():
            start_idx = 0
            while len(file_paths) - start_idx >= batch_size:
                flag_fit = False
                sequence_data = []
                for idx in range(start_idx, len(file_paths)):
                    try:
                        sequence = np.load(file_paths[idx])
                        if np.isnan(sequence).any():
                            continue
                        sequence_data.append(sequence)
                        if len(sequence_data) == batch_size:
                            flag_fit = True
                            start_idx = idx + 1
                            break
                    except Exception:
                        continue
                if flag_fit:
                    sequence_batch = np.stack(sequence_data)
                    yield sequence_batch
        return tf.data.Dataset.from_generator(generator, tf.uint8)


    def train(self, epochs, batch_size, file_paths):
        cv2.namedWindow('Check training', cv2.WINDOW_NORMAL)
        cv2.resizeWindow(winname='Check training', width=1280, height=720)
        sequence_discriminator_output1 = None
        label_real1 = None
        label_fake1 = None
        sequence_discriminator_output2 = None
        label_real2 = None
        label_fake2 = None
        sequence_dataset = self.get_sequence_dataset(batch_size, file_paths)
        for epoch in range(epochs):
            for batch, sequence_batch in enumerate(sequence_dataset):
                try:
                    ref_frame_batch = sequence_batch[:, 0, ...]
                    ref_frame_batch = (tf.cast(ref_frame_batch, tf.float32) - 127.5) / 127.5
                    real_sequence_batch = sequence_batch
                    real_sequence_batch = (tf.cast(real_sequence_batch, tf.float32) - 127.5) / 127.5
                    fake_sequence_batch = self.sequence_generator.predict([ref_frame_batch])
                    if ref_frame_batch.shape[1] > ref_frame_batch.shape[2]:
                        if sequence_discriminator_output1 is None:
                            sequence_discriminator_output1 = self.sequence_discriminator.predict([real_sequence_batch])
                            label_real1 = tf.ones_like(sequence_discriminator_output1, dtype=tf.float32)
                            label_fake1 = tf.zeros_like(sequence_discriminator_output1, dtype=tf.float32)
                        self.sequence_discriminator.trainable = True
                        sequence_discriminator_loss_real = self.sequence_discriminator.train_on_batch([real_sequence_batch], label_real1)
                        sequence_discriminator_loss_fake = self.sequence_discriminator.train_on_batch([fake_sequence_batch], label_fake1)
                        self.sequence_discriminator.trainable = False
                        sequence_generator_loss = self.sequence_gan.train_on_batch([ref_frame_batch, real_sequence_batch], label_real1)
                    else:
                        if sequence_discriminator_output2 is None:
                            sequence_discriminator_output2 = self.sequence_discriminator.predict([real_sequence_batch])
                            label_real2 = tf.ones_like(sequence_discriminator_output2, dtype=tf.float32)
                            label_fake2 = tf.zeros_like(sequence_discriminator_output2, dtype=tf.float32)
                        self.sequence_discriminator.trainable = True
                        sequence_discriminator_loss_real = self.sequence_discriminator.train_on_batch([real_sequence_batch], label_real2)
                        sequence_discriminator_loss_fake = self.sequence_discriminator.train_on_batch([fake_sequence_batch], label_fake2)
                        self.sequence_discriminator.trainable = False
                        sequence_generator_loss = self.sequence_gan.train_on_batch([ref_frame_batch, real_sequence_batch], label_real2)
                    if np.isnan(sequence_discriminator_loss_real) or np.isnan(sequence_discriminator_loss_fake) or np.isnan(sequence_generator_loss):
                        self.build_or_load_models()
                        continue
                except Exception as e:
                    print(e)
                    time.sleep(3)
                    self.build_or_load_models()
                    continue
                try:
                    os.system('cls') if os.name == 'nt' else os.system('clear')
                    print(f'\nEpoch {epoch + 1}, Batch {batch + 1}\n  Discriminator Loss real: {sequence_discriminator_loss_real} / fake: {sequence_discriminator_loss_fake}\n  Generator Loss: {sequence_generator_loss}\n')
                    goal_img1 = cv2.resize(cv2.cvtColor(((np.array(real_sequence_batch[0, 0, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    goal_img2 = cv2.resize(cv2.cvtColor(((np.array(real_sequence_batch[0, 1, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    goal_img3 = cv2.resize(cv2.cvtColor(((np.array(real_sequence_batch[0, 2, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    goal_img4 = cv2.resize(cv2.cvtColor(((np.array(real_sequence_batch[0, 3, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    goal_img5 = cv2.resize(cv2.cvtColor(((np.array(real_sequence_batch[0, 4, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    gen_img1 = cv2.resize(cv2.cvtColor(((np.array(fake_sequence_batch[0, 0, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    gen_img2 = cv2.resize(cv2.cvtColor(((np.array(fake_sequence_batch[0, 1, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    gen_img3 = cv2.resize(cv2.cvtColor(((np.array(fake_sequence_batch[0, 2, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    gen_img4 = cv2.resize(cv2.cvtColor(((np.array(fake_sequence_batch[0, 3, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    gen_img5 = cv2.resize(cv2.cvtColor(((np.array(fake_sequence_batch[0, 4, ...]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (1280, 720))
                    chk_img = np.concatenate([
                        np.concatenate([goal_img1[:360, :256], goal_img2[:360, 256:512], goal_img3[:360, 512:768], goal_img4[:360, 768:1024], goal_img5[:360, 1024:]], axis=1), 
                        np.concatenate([gen_img1[360:, :256], gen_img2[360:, 256:512], gen_img3[360:, 512:768], gen_img4[360:, 768:1024], gen_img5[360:, 1024:]], axis=1)
                        ], axis=0)
                    cv2.putText(chk_img, 'Goal_1', (0, 360), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Goal_2', (256, 360), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Goal_3', (512, 360), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Goal_4', (768, 360), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Goal_5', (1024, 360), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Gen_1', (0, 720), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Gen_2', (256, 720), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Gen_3', (512, 720), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Gen_4', (768, 720), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, 'Gen_5', (1024, 720), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.imshow('Check training', chk_img)
                    cv2.waitKey(1)
                except Exception as e:
                    print(e)
                    time.sleep(3)
                if batch % 1000 == 999:
                    self.save_model()
            self.save_model()
        cv2.destroyAllWindows()
