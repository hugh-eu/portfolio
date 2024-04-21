import os
import cv2
import time
import numpy as np
import random
import tensorflow as tf

class Model:
    def __init__(self, check_points_dir, model_dir):
        self.shape = (144, 256, 3)
        self.frame_generator = self.build_frame_generator()
        self.frame_generator_optimizer = tf.keras.optimizers.Adam(learning_rate=0.0002, beta_1=0.5, beta_2=0.999)
        self.frame_discriminator = self.build_frame_discriminator()
        self.frame_discriminator_optimizer = tf.keras.optimizers.Adam(learning_rate=0.0002, beta_1=0.5, beta_2=0.999)
        self.check_point = tf.train.Checkpoint(generator=self.frame_generator, generator_optimizer=self.frame_generator_optimizer, discriminator=self.frame_discriminator, discriminator_optimizer=self.frame_discriminator_optimizer)
        self.check_point_dir = check_points_dir
        self.check_point_manager = tf.train.CheckpointManager(self.check_point, self.check_point_dir, max_to_keep=2, checkpoint_name="ckpt")
        if tf.train.latest_checkpoint(self.check_point_dir):
            self.check_point.restore(tf.train.latest_checkpoint(self.check_point_dir))
        else:
            self.check_point_manager.save()
        self.frame_generator_model_path = os.path.join(model_dir, "frame_generator_model.h5")


    def build_frame_generator(self):
        frame_generator_input = tf.keras.layers.Input(shape=self.shape)
        
        x1 = tf.keras.layers.Conv2D(64, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(frame_generator_input)
        x1 = tf.keras.layers.BatchNormalization()(x1)
        x1 = tf.keras.layers.LeakyReLU(0.2)(x1)
        x1 = tf.keras.layers.Dropout(0.3)(x1)
        
        x2 = tf.keras.layers.Conv2D(x1.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x1)
        x2 = tf.keras.layers.BatchNormalization()(x2)
        x2 = tf.keras.layers.LeakyReLU(0.2)(x2)
        x2 = tf.keras.layers.Dropout(0.3)(x2)
        
        x3 = tf.keras.layers.Conv2D(x2.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x2)
        x3 = tf.keras.layers.BatchNormalization()(x3)
        x3 = tf.keras.layers.LeakyReLU(0.2)(x3)
        x3 = tf.keras.layers.Dropout(0.3)(x3)
        
        x4 = tf.keras.layers.Conv2D(x3.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x3)
        x4 = tf.keras.layers.BatchNormalization()(x4)
        x4 = tf.keras.layers.LeakyReLU(0.2)(x4)
        x4 = tf.keras.layers.Dropout(0.3)(x4)
        
        x5 = tf.keras.layers.Conv2D(x4.shape[-1], kernel_size=(6, 8), strides=(3, 4), padding="same", use_bias=False)(x4)
        x5 = tf.keras.layers.BatchNormalization()(x5)
        x5 = tf.keras.layers.LeakyReLU(0.2)(x5)
        x5 = tf.keras.layers.Dropout(0.3)(x5)
        
        x = tf.keras.layers.Conv2D(x5.shape[-1], kernel_size=(6, 8), strides=(3, 4), padding="same", use_bias=False)(x5)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.LeakyReLU(0.2)(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Conv2DTranspose(x.shape[-1], kernel_size=(6, 8), strides=(3, 4), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.ReLU()(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Concatenate()([x5, x])
        
        x = tf.keras.layers.Conv2DTranspose(x.shape[-1] // 2, kernel_size=(6, 8), strides=(3, 4), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.ReLU()(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Concatenate()([x4, x])
        
        x = tf.keras.layers.Conv2DTranspose(x.shape[-1] // 4, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.ReLU()(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Concatenate()([x3, x])
        
        x = tf.keras.layers.Conv2DTranspose(x.shape[-1] // 4, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.ReLU()(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Concatenate()([x2, x])
        
        x = tf.keras.layers.Conv2DTranspose(x.shape[-1] // 4, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.ReLU()(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Concatenate()([x1, x])
        
        frame_generator_output = tf.keras.layers.Conv2DTranspose(3, kernel_size=(4, 4), strides=(2, 2), padding="same", activation="tanh")(x)
        return tf.keras.Model(inputs=[frame_generator_input], outputs=frame_generator_output, name="frame_generator")


    def build_frame_discriminator(self):
        previous_frame_input = tf.keras.layers.Input(shape=self.shape)
        current_frame_input = tf.keras.layers.Input(shape=self.shape)
        
        x = tf.keras.layers.Concatenate()([previous_frame_input, current_frame_input])
        
        x = tf.keras.layers.Conv2D(64, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.LeakyReLU(0.2)(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Conv2D(x.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.LeakyReLU(0.2)(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Conv2D(x.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.LeakyReLU(0.2)(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        x = tf.keras.layers.Conv2D(x.shape[-1] * 2, kernel_size=(4, 4), strides=(2, 2), padding="same", use_bias=False)(x)
        x = tf.keras.layers.BatchNormalization()(x)
        x = tf.keras.layers.LeakyReLU(0.2)(x)
        x = tf.keras.layers.Dropout(0.3)(x)
        
        frame_discriminator_output = tf.keras.layers.Conv2D(1, kernel_size=(4, 4), padding="same", activation="sigmoid")(x)
        return tf.keras.Model(inputs=[previous_frame_input, current_frame_input], outputs=frame_discriminator_output, name="frame_discriminator")


    def get_sequence_dataset(self, batch_size, file_paths):
        def generator():
            start_idx = 0
            while len(file_paths) - start_idx >= batch_size:
                flag_fit = False
                previous_frame_data = []
                current_frame_data = []
                for idx in range(start_idx, len(file_paths)):
                    try:
                        previous_frame = np.load(file_paths[idx])
                        current_frame = np.load(file_paths[idx].replace("_p.npy", "_c.npy"))
                        if np.isnan(previous_frame).any().any().any() or np.isnan(current_frame).any().any().any():
                            continue
                        previous_frame_data.append(previous_frame)
                        current_frame_data.append(current_frame)
                        if len(previous_frame_data) == batch_size:
                            flag_fit = True
                            start_idx = idx + 1
                            break
                    except Exception:
                        continue
                if flag_fit:
                    previous_frame_batch = np.stack(previous_frame_data)
                    current_frame_batch = np.stack(current_frame_data)
                    yield previous_frame_batch, current_frame_batch
        return tf.data.Dataset.from_generator(generator, (tf.uint8, tf.uint8))


    def train(self, epochs, batch_size, file_paths):
        cv2.namedWindow("Check training", cv2.WINDOW_NORMAL)
        cv2.resizeWindow(winname="Check training", width=1536, height=288)        
        for epoch in range(epochs):
            random.shuffle(file_paths)
            sequence_dataset = self.get_sequence_dataset(batch_size, file_paths)
            for batch, (previous_frame_batch, current_frame_batch) in enumerate(sequence_dataset):
                try:
                    previous_frame_batch = (tf.cast(previous_frame_batch, tf.float32) - 127.5) / 127.5
                    current_frame_batch = (tf.cast(current_frame_batch, tf.float32) - 127.5) / 127.5
                    with tf.GradientTape() as generator_tape, tf.GradientTape() as discriminator_tape:
                        frame_generator_output = self.frame_generator([previous_frame_batch], training=True)
                        frame_discriminator_output_fake = self.frame_discriminator([previous_frame_batch, frame_generator_output], training=True)
                        frame_discriminator_output_real = self.frame_discriminator([previous_frame_batch, current_frame_batch], training=True)
                        frame_generator_bce_loss = tf.reduce_mean(tf.keras.losses.binary_crossentropy(tf.ones_like(frame_discriminator_output_fake), frame_discriminator_output_fake))
                        frame_generator_l1_loss = tf.reduce_mean(tf.keras.losses.mean_absolute_error(frame_generator_output, current_frame_batch))
                        frame_generator_total_loss = (frame_generator_bce_loss * 1) + (frame_generator_l1_loss * 100)
                        frame_discriminator_fake_loss = tf.reduce_mean(tf.keras.losses.binary_crossentropy(tf.zeros_like(frame_discriminator_output_fake), frame_discriminator_output_fake))
                        frame_discriminator_real_loss = tf.reduce_mean(tf.keras.losses.binary_crossentropy(tf.ones_like(frame_discriminator_output_real), frame_discriminator_output_real))
                        frame_discriminator_total_loss = frame_discriminator_fake_loss + frame_discriminator_real_loss
                    frame_generator_gradients = generator_tape.gradient(frame_generator_total_loss, self.frame_generator.trainable_variables)
                    frame_discriminator_gradients = discriminator_tape.gradient(frame_discriminator_total_loss, self.frame_discriminator.trainable_variables)
                    self.frame_generator_optimizer.apply_gradients(zip(frame_generator_gradients, self.frame_generator.trainable_variables))
                    self.frame_discriminator_optimizer.apply_gradients(zip(frame_discriminator_gradients, self.frame_discriminator.trainable_variables))
                    if np.isnan(frame_generator_total_loss) or np.isnan(frame_discriminator_total_loss):
                        self.check_point.restore(tf.train.latest_checkpoint(self.check_point_dir))
                        continue
                except Exception as e:
                    print(e)
                    time.sleep(3)
                    self.check_point.restore(tf.train.latest_checkpoint(self.check_point_dir))
                    continue
                try:
                    os.system("cls") if os.name == "nt" else os.system("clear")
                    print(f"\nEpoch {epoch + 1}, Batch {batch + 1}" + 
                          f"\n  Generator Loss : {frame_generator_total_loss}" + 
                          f"\n    Gen BCE Loss : {frame_generator_bce_loss}" + 
                          f"\n    Gen MAE Loss : {frame_generator_l1_loss * 100}" + 
                          f"\n  Discriminator Loss : {frame_discriminator_total_loss}" + 
                          f"\n    Disc Fake Loss : {frame_discriminator_fake_loss}" + 
                          f"\n    Disc Real Loss : {frame_discriminator_real_loss}\n")
                    ref_img = cv2.resize(cv2.cvtColor(((np.array(previous_frame_batch[0]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (512, 288))
                    gen_img = cv2.resize(cv2.cvtColor(((np.array(frame_generator_output[0]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (512, 288))
                    goal_img = cv2.resize(cv2.cvtColor(((np.array(current_frame_batch[0]) + 1) * 127.5).astype(np.uint8), cv2.COLOR_RGB2BGR), (512, 288))
                    chk_img = np.concatenate([ref_img, gen_img, goal_img], axis=1)
                    cv2.putText(chk_img, "Ref", (0, 288), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, "Gen", (512, 288), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.putText(chk_img, "Goal", (1024, 288), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 255), 2)
                    cv2.imshow("Check training", chk_img)
                    cv2.waitKey(1)
                except Exception as e:
                    print(e)
                    time.sleep(3)
            self.check_point_manager.save()
        cv2.destroyAllWindows()
        self.frame_generator.save(self.frame_generator_model_path, overwrite=True, include_optimizer=False, save_format="h5")
