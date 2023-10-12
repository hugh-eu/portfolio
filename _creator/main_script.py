import os
import time
import random
import shutil
import datetime
import mimetypes
import tensorflow as tf
from preprocess import Preprocessor
from model import Model
from generator import Generator


def choose_frame_shape():
    while True:
        print('Choose a resolution:')
        print('  1. 256x144')
        print('  2. 426x240')
        print('  3. 640x360')
        print('  4. 854x480')
        print('  5. 1280x720')
        print('  6. 1920x1080')
        res = input('Enter the number of the resolution you want: ')
        if res == '1':
            return (144, 256, 3)
        elif res == '2':
            return (240, 426, 3)
        elif res == '3':
            return (360, 640, 3)
        elif res == '4':
            return (480, 854, 3)
        elif res == '5':
            return (720, 1280, 3)
        elif res == '6':
            return (1080, 1920, 3)
        else:
            print('Invalid choice.')
            time.sleep(3)


def main():
    print('Run Creator...')
    tf.keras.mixed_precision.set_global_policy('float32')
    while True:
        print('Choose an environment:')
        gpu_or_cpu = input('  1. gpu  2. cpu  ')
        if gpu_or_cpu == '1':
            gpus = tf.config.experimental.list_physical_devices('GPU')
            if gpus:
                try:
                    mem = int(input('  gpu memory(0~4 GB): '))
                except Exception as e:
                    print(e)
                    time.sleep(3)
                    continue
                if mem < 0 or mem > 4:
                    print('Invalid choice.')
                    time.sleep(3)
                    continue
                for gpu in gpus:
                    if mem:
                        tf.config.experimental.set_virtual_device_configuration(
                            gpu, 
                            [tf.config.experimental.VirtualDeviceConfiguration(memory_limit=mem*1024)]
                        )
                    else:
                        tf.config.experimental.set_memory_growth(gpu, True)
        elif gpu_or_cpu == '2':
            gpus = tf.config.experimental.list_physical_devices('GPU')
            if gpus:
                tf.config.experimental.set_visible_devices([], 'GPU')
        else:
            print('Invalid choice.')
            time.sleep(3)
            continue
        break
    input_videos_dir = '/home/hugh_eu/ai/creator/resource/input_videos'
    os.makedirs(input_videos_dir, exist_ok=True)
    output_videos_dir = '/home/hugh_eu/ai/creator/resource/output_videos'
    os.makedirs(output_videos_dir, exist_ok=True)
    model_dir = '/home/hugh_eu/ai/creator/resource/model'
    os.makedirs(model_dir, exist_ok=True)
    backup_model_dir = '/home/hugh_eu/ai/creator/resource/model_bak'
    os.makedirs(backup_model_dir, exist_ok=True)
    sample_frame_dir = '/home/hugh_eu/ai/creator/resource/sample_frame'
    os.makedirs(sample_frame_dir, exist_ok=True)
    while True:
        try:
            os.system('cls') if os.name == 'nt' else os.system('clear')
            print(f'\n[GAN model]')
            print('Choose an action:')
            print('  1. Preprocess video frames and Train the GAN model')
            print('  2. Generate a video')
            print('  3. Quit')
            act = input('Enter the number of the action you want to perform: ')
            if act == '1':
                model = Model(model_dir, backup_model_dir)
                if model.sequence_discriminator is not None and model.sequence_generator is not None and model.sequence_gan is not None:
                    preprocessor = Preprocessor(input_videos_dir)
                    sequence_length = 5
                    frame_shapes = [(128, 256, 3)]
                    epochs = 100
                    batch_sizes = [1]
                    for i in range(len(frame_shapes)):
                        preprocessed_data_dir = f'/home/hugh_eu/ai/creator/resource/preprocessed_data/{frame_shapes[i][1]}x{frame_shapes[i][0]}'
                        os.makedirs(preprocessed_data_dir, exist_ok=True)
                        file_paths = preprocessor.preprocess_videos(sequence_length, frame_shapes[i], preprocessed_data_dir)
                        model.train(epochs, batch_sizes[i], file_paths)
                    print('...Done')
                    input()
                else:
                    print('Please check the model before doing this action.')
                    input()
                tf.keras.backend.clear_session()
            elif act == '2':
                model = Model(model_dir, backup_model_dir)
                if model.sequence_discriminator is not None and model.sequence_generator is not None and model.sequence_gan is not None:
                    video_generator = Generator(model)
                    frame_shape = choose_frame_shape()
                    print(f'  frame_shape: {frame_shape}')
                    duration = int(input('  generated_video_duration_seconds: '))
                    fps = int(input('  fps: '))
                    sample_frame_dir_res = f'{sample_frame_dir}/{frame_shape[1]}x{frame_shape[0]}'
                    os.makedirs(sample_frame_dir_res, exist_ok=True)
                    sample_frames = [f for f in os.listdir(sample_frame_dir_res) if f.endswith('.png')]
                    if len(sample_frames) > 0:
                        sample_frame = random.choice(sample_frames)
                        sample_frame_path = f'{sample_frame_dir_res}/{sample_frame}'
                        timestamp = f'{datetime.datetime.now():%Y%m%d%H%M%S}'
                        output_filename = f'[{timestamp}]_{frame_shape[1]}x{frame_shape[0]}_{fps}fps.mp4'
                        output_path = f'{output_videos_dir}/{output_filename}'
                        video_generator.generate_and_save_video(duration, fps, sample_frame_path, output_path)
                        print('...Done')
                        input()
                    else:
                        print('There are no images to reference.')
                        time.sleep(3)
                else:
                    print('Please check the model before doing this action.')
                    input()
                tf.keras.backend.clear_session()
            elif act == '3':
                break
            else:
                print('Invalid choice.')
                time.sleep(3)
        except Exception as e:
            print(e)
            time.sleep(3)
            continue


if __name__ == '__main__':
    main()
