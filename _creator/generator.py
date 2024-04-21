import os
import cv2
import numpy as np
import tensorflow as tf
from tqdm import tqdm

class Generator:
    def __init__(self, model_dir):
        self.frame_generator_model_path = os.path.join(model_dir, "frame_generator_model.h5")
        self.frame_generator = tf.keras.models.load_model(self.frame_generator_model_path, compile=False)


    def generate_and_save_video(self, duration, fps, sample_frame_path, output_video_path):
        original_frame = cv2.imread(sample_frame_path)
        original_frame_shape = original_frame.shape
        if original_frame_shape[0] > original_frame_shape[1]:
            writer = cv2.VideoWriter(output_video_path, cv2.VideoWriter_fourcc(*"mp4v"), fps, (144, 256))
            previous_frame = cv2.resize(original_frame, (144, 256))
            writer.write(previous_frame)
            previous_frame = cv2.rotate(previous_frame, cv2.ROTATE_90_CLOCKWISE)
        else:
            writer = cv2.VideoWriter(output_video_path, cv2.VideoWriter_fourcc(*"mp4v"), fps, (256, 144))
            previous_frame = cv2.resize(original_frame, (256, 144))
            writer.write(previous_frame)
        previous_frame = cv2.cvtColor(previous_frame, cv2.COLOR_BGR2RGB)
        for _ in tqdm(range(int(duration * fps) - 1)):
            try:
                mean_r = np.mean(previous_frame[:, :, 0])
                mean_g = np.mean(previous_frame[:, :, 1])
                mean_b = np.mean(previous_frame[:, :, 2])
                piece_range_r = min(mean_r, 255 - mean_r) * 2 / 6
                piece_range_g = min(mean_g, 255 - mean_g) * 2 / 6
                piece_range_b = min(mean_b, 255 - mean_b) * 2 / 6
                max_indices = np.argmax(previous_frame, axis=2)
                max_values = previous_frame[np.arange(previous_frame.shape[0])[:, None], np.arange(previous_frame.shape[1]), max_indices]
                previous_frame = np.zeros_like(previous_frame).astype(np.uint8)
                for i in range(3):
                    if i == 0:
                        previous_frame[:, :, i][(max_indices == i) & (max_values <= mean_r - piece_range_r)] = int(mean_r - (piece_range_r * 2))
                        previous_frame[:, :, i][(max_indices == i) & (mean_r - piece_range_r < max_values) & (max_values <= mean_r + piece_range_r)] = int(mean_r)
                        previous_frame[:, :, i][(max_indices == i) & (mean_r + piece_range_r < max_values)] = int(mean_r + (piece_range_r * 2))
                    elif i == 1:
                        previous_frame[:, :, i][(max_indices == i) & (max_values <= mean_g - piece_range_g)] = int(mean_g - (piece_range_g * 2))
                        previous_frame[:, :, i][(max_indices == i) & (mean_g - piece_range_g < max_values) & (max_values <= mean_g + piece_range_g)] = int(mean_g)
                        previous_frame[:, :, i][(max_indices == i) & (mean_g + piece_range_g < max_values)] = int(mean_g + (piece_range_g * 2))
                    else:
                        previous_frame[:, :, i][(max_indices == i) & (max_values <= mean_b - piece_range_b)] = int(mean_b - (piece_range_b * 2))
                        previous_frame[:, :, i][(max_indices == i) & (mean_b - piece_range_b < max_values) & (max_values <= mean_b + piece_range_b)] = int(mean_b)
                        previous_frame[:, :, i][(max_indices == i) & (mean_b + piece_range_b < max_values)] = int(mean_b + (piece_range_b * 2))
                previous_frame = (previous_frame.astype(np.float32) - 127.5) / 127.5
                previous_frame = np.expand_dims(previous_frame, axis=0)
                generated_frame = self.frame_generator.predict_on_batch([previous_frame])[0]
                generated_frame = ((generated_frame + 1) * 127.5).astype(np.uint8)
                writer.write(cv2.cvtColor(cv2.rotate(generated_frame, cv2.ROTATE_90_COUNTERCLOCKWISE) if original_frame_shape[0] > original_frame_shape[1] else generated_frame, cv2.COLOR_RGB2BGR))
                previous_frame = generated_frame
                rows, cols, _ = generated_frame.shape
                dy = np.random.randint(-2, 2, (rows, cols))
                dx = np.random.randint(-2, 2, (rows, cols))
                for y in range(rows):
                    for x in range(cols):
                        new_y = np.clip(y + dy[y, x], 0, rows - 1)
                        new_x = np.clip(x + dx[y, x], 0, cols - 1)
                        previous_frame[new_y, new_x] = generated_frame[y, x]
            except Exception as e:
                print(e)
                return
        writer.release()
