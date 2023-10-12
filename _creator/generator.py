import cv2
import time
import numpy as np


class Generator:
    def __init__(self, model):
        self.model = model


    def generate_and_save_video(self, duration, fps, sample_frame_path, output_path):
        ref_frame = cv2.imread(sample_frame_path)
        ref_frame_shape = ref_frame.shape
        writer = cv2.VideoWriter(output_path, cv2.VideoWriter_fourcc(*'mp4v'), fps, (ref_frame_shape[1], ref_frame_shape[0]))
        writer.write(ref_frame)
        if ref_frame_shape[0] % 64 != 0 or ref_frame_shape[1] % 64 != 0:
            ref_frame = cv2.resize(ref_frame, 
                                   (((ref_frame_shape[1] // 64) + 1) * 64 if ref_frame_shape[1] % 64 != 0 else ref_frame_shape[1], 
                                    ((ref_frame_shape[0] // 64) + 1) * 64 if ref_frame_shape[0] % 64 != 0 else ref_frame_shape[0]))
        ref_frame = cv2.cvtColor(ref_frame, cv2.COLOR_BGR2RGB)
        for _ in range(int(duration * fps / 4)):
            try:
                ref_frame = (ref_frame.astype(np.float32) - 127.5) / 127.5
                ref_frame = np.expand_dims(ref_frame, axis=0)
                generated_sequence = self.model.sequence_generator.predict([ref_frame])[0]
                for idx, frame in enumerate(generated_sequence):
                    if idx !=0:
                        frame = ((frame + 1) * 127.5).astype(np.uint8)
                        writer.write(
                            cv2.cvtColor(
                                cv2.resize(frame, (ref_frame_shape[1], ref_frame_shape[0])) if ref_frame_shape[0] % 64 != 0 or ref_frame_shape[1] % 64 != 0 else frame, 
                                cv2.COLOR_RGB2BGR))
                        if idx == len(generated_sequence) - 1:
                            ref_frame = frame
            except Exception as e:
                print(e)
                time.sleep(3)
                continue
        writer.release()
