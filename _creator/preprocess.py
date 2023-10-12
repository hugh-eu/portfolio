import os
import cv2
import time
import glob
import mimetypes
import numpy as np


class Preprocessor:
    def __init__(self, input_videos_dir):
        self.input_videos_dir = input_videos_dir


    def video_to_sequences(self, sequence_length, frame_shape, file_path, output_sequence_dir):
        cap = cv2.VideoCapture(file_path)
        if not cap.isOpened():
            print('Error: Could not open video.')
            time.sleep(3)
            return
        sequence_count = 0
        buffer = []
        while True:
            ret, frame = cap.read()
            if not ret:
                break
            if frame.shape[0] > frame.shape[1]:
                frame = cv2.rotate(frame, cv2.ROTATE_90_CLOCKWISE)
            frame = cv2.resize(frame, (frame_shape[1], frame_shape[0]))
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            buffer.append(frame)
            if len(buffer) == sequence_length:
                sequence_count += 1
                sequence_filename = f'{output_sequence_dir}/frame_{sequence_count:05d}.npy'
                if os.path.exists(sequence_filename):
                    continue
                np.save(sequence_filename, np.array(buffer))
                buffer = []
        cap.release()


    def preprocess_videos(self, sequence_length, frame_shape, preprocessed_data_dir):
        for filename in os.listdir(self.input_videos_dir):
            file_path = f'{self.input_videos_dir}/{filename}'
            output_sequence_dir = f'{preprocessed_data_dir}/{os.path.splitext(filename)[0]}'
            os.makedirs(output_sequence_dir, exist_ok=True)
            mime_type, _ = mimetypes.guess_type(file_path)
            if mime_type and mime_type.startswith('video'):
                self.video_to_sequences(sequence_length, frame_shape, file_path, output_sequence_dir)
        return sorted(glob.glob(f'{preprocessed_data_dir}/**/*.npy', recursive=True))
