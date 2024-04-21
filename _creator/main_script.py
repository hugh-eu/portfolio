import os
import time
import random
import shutil
import datetime
import mimetypes
import tensorflow as tf
from model import Model
from generator import Generator
from preprocess import Preprocessor

def main():
    print("Run Creator...")
    tf.keras.mixed_precision.set_global_policy("float32")
    gpus = tf.config.experimental.list_physical_devices("GPU")
    if gpus:
        try:
            for gpu in gpus:
                tf.config.experimental.set_virtual_device_configuration(gpu, [tf.config.experimental.VirtualDeviceConfiguration(memory_limit=1024*4)])
        except RuntimeError as e:
            print(e)
            return
    base_dir = os.path.join("C:\\" if os.name == "nt" else "/", "Users", "hugh_", "Multipurpose", "creator", "resource")
    check_points_dir = os.path.join(base_dir, "check_points")
    os.makedirs(check_points_dir, exist_ok=True)
    input_videos_dir = os.path.join(base_dir, "input_videos")
    os.makedirs(input_videos_dir, exist_ok=True)
    model_dir = os.path.join(base_dir, "model")
    os.makedirs(model_dir, exist_ok=True)
    output_videos_dir = os.path.join(base_dir, "output_videos")
    os.makedirs(output_videos_dir, exist_ok=True)
    preprocessed_data_dir = os.path.join(base_dir, "preprocessed_data")
    os.makedirs(preprocessed_data_dir, exist_ok=True)
    sample_frame_dir = os.path.join(base_dir, "sample_frame")
    os.makedirs(sample_frame_dir, exist_ok=True)
    while True:
        try:
            os.system("cls") if os.name == "nt" else os.system("clear")
            print("\n[GAN model]")
            print("Choose an action:")
            print("  1. Preprocess video frames and Train the GAN model")
            print("  2. Generate a video")
            act = input("Enter the number of the action you want to perform: ")
            if act == "1":
                preprocessor = Preprocessor(input_videos_dir)
                file_paths = preprocessor.preprocess_videos(preprocessed_data_dir)
                del preprocessor
                if file_paths:
                    model = Model(check_points_dir, model_dir)
                    if model.frame_discriminator is not None and model.frame_generator is not None:
                        epochs = 10
                        batch_sizes = 16
                        model.train(epochs, batch_sizes, file_paths)
                        for file_name in os.listdir(preprocessed_data_dir):
                            file_path = os.path.join(preprocessed_data_dir, file_name)
                            if os.path.isfile(file_path) or os.path.islink(file_path):
                                os.unlink(file_path)
                            elif os.path.isdir(file_path):
                                shutil.rmtree(file_path)
                        print("...Done")
                        return
                    else:
                        print("Please check the model before doing this action.")
                        input()
                    del model
                else:
                    print("There are no images for training.")
                    time.sleep(3)
            elif act == "2":
                video_generator = Generator(model_dir)
                duration = 60
                fps = 30
                sample_frames = [f for f in os.listdir(sample_frame_dir) if mimetypes.guess_type(f)[0] and mimetypes.guess_type(f)[0].startswith("image")]
                if len(sample_frames) > 0:
                    sample_frame = random.choice(sample_frames)
                    sample_frame_path = os.path.join(sample_frame_dir, sample_frame)
                    timestamp = f"{datetime.datetime.now():%y%m%d%H%M%S}"
                    output_video_name = f"[{timestamp}]_{sample_frame}_{fps}fps.mp4"
                    output_video_path = os.path.join(output_videos_dir, output_video_name)
                    video_generator.generate_and_save_video(duration, fps, sample_frame_path, output_video_path)
                    print("...Done")
                    return
                else:
                    print("There are no images to reference.")
                    time.sleep(3)
                del video_generator
            else:
                print("Invalid choice.")
                time.sleep(3)
        except Exception as e:
            print(e)
            return


if __name__ == "__main__":
    main()
