import os
import cv2
import time
import glob
import mimetypes
import numpy as np
from tqdm import tqdm

class Preprocessor:
    def __init__(self, input_videos_dir):
        self.input_videos_dir = input_videos_dir


    def video_to_sequences(self, file_path, output_frames_dir):
        cap = cv2.VideoCapture(file_path)
        if not cap.isOpened():
            print("Error: Could not open video.")
            time.sleep(3)
            return
        sequence_count = 0
        previous_frame = None
        while True:
            ret, current_frame = cap.read()
            if not ret:
                break
            if current_frame.shape[0] > current_frame.shape[1]:
                current_frame = cv2.rotate(current_frame, cv2.ROTATE_90_CLOCKWISE)
            current_frame = cv2.resize(current_frame, (256, 144))
            current_frame = cv2.cvtColor(current_frame, cv2.COLOR_BGR2RGB)
            mean_r = np.mean(current_frame[:, :, 0])
            mean_g = np.mean(current_frame[:, :, 1])
            mean_b = np.mean(current_frame[:, :, 2])
            piece_range_r = min(mean_r, 255 - mean_r) * 2 / 6
            piece_range_g = min(mean_g, 255 - mean_g) * 2 / 6
            piece_range_b = min(mean_b, 255 - mean_b) * 2 / 6
            if previous_frame is None:
                max_indices = np.argmax(current_frame, axis=2)
                max_values = current_frame[np.arange(current_frame.shape[0])[:, None], np.arange(current_frame.shape[1]), max_indices]
                previous_frame = np.zeros_like(current_frame).astype(np.uint8)
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
                continue
            sequence_count += 1
            previous_frame_path = os.path.join(output_frames_dir, f"frame_{sequence_count:05d}_p.npy")
            current_frame_path = os.path.join(output_frames_dir, f"frame_{sequence_count:05d}_c.npy")
            if not os.path.exists(previous_frame_path) or not os.path.exists(current_frame_path):
                np.save(previous_frame_path, np.array(previous_frame))
                np.save(current_frame_path, np.array(current_frame))
            max_indices = np.argmax(current_frame, axis=2)
            max_values = current_frame[np.arange(current_frame.shape[0])[:, None], np.arange(current_frame.shape[1]), max_indices]
            previous_frame = np.zeros_like(current_frame).astype(np.uint8)
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
        cap.release()


    def preprocess_videos(self, preprocessed_data_dir):
        for file_name in tqdm(os.listdir(self.input_videos_dir), desc="preprocess_videos"):
            file_path = os.path.join(self.input_videos_dir, file_name)
            output_frames_dir = os.path.join(preprocessed_data_dir, f"{os.path.splitext(file_name)[0]}")
            os.makedirs(output_frames_dir, exist_ok=True)
            if mimetypes.guess_type(file_path)[0] and mimetypes.guess_type(file_path)[0].startswith("video"):
                self.video_to_sequences(file_path, output_frames_dir)
            os.remove(file_path)
        return sorted(glob.glob(os.path.join(preprocessed_data_dir, "**", "*_p.npy"), recursive=True))
