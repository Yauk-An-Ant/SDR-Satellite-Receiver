import math
import struct

def write_to_bin(filename, num_samples, data_real, data_imag):
    with open(f"data/{filename}", "wb") as f:
        for i in range(num_samples):
            real = data_real[i]
            imag = data_imag[i]
            f.write(struct.pack("ff", real, imag))

    print("Completed file generation.");

def initial_test_data_gen(num_samples):
    frequency = 10.0
    real = []
    imag = []

    for i in range(num_samples):
        t = i / num_samples
        real.append(math.cos(2 * math.pi * frequency * t))
        imag.append(math.sin(2 * math.pi * frequency * t))

    return real, imag

if __name__ == "__main__":
    num_samples = 1056
    real, imag = initial_test_data_gen(num_samples);

    write_to_bin("test_recording.bin", num_samples, real, imag)