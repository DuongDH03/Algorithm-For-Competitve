import numpy as np
import matplotlib.pyplot as plt

# Định nghĩa hàm xung vuông
def square_pulse(t, T):
    return np.where((t % T) < (T/2), 1, 0)

# Định nghĩa hàm biến đổi Fourier
def fourier_transform(t, h_t):
    f = np.fft.fftfreq(len(t), d=(t[1]-t[0]))
    H_f = np.fft.fft(h_t)
    return f, H_f

# Thời gian
t = np.linspace(0, 1, 500, endpoint=False)

# Chu kỳ của xung vuông
T = 0.1

# Tính đáp ứng xung
h_t = square_pulse(t, T)

# Tính đáp ứng tần số
f, H_f = fourier_transform(t, h_t)

# Vẽ đáp ứng xung
plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(t, h_t)
plt.title('Đáp ứng xung')
plt.xlabel('Thời gian (s)')
plt.ylabel('h(t)')

# Vẽ đáp ứng tần số
plt.subplot(2, 1, 2)
plt.plot(f, np.abs(H_f))
plt.title('Đáp ứng tần số')
plt.xlabel('Tần số (Hz)')
plt.ylabel('|H(f)|')

# Hiển thị biểu đồ
plt.tight_layout()
plt.show()
