import numpy as np
import matplotlib.pyplot as plt

# 设置参数
t = np.linspace(-4, 14, 1000)  # 时间变量，范围从-10到10
a = 0.6                           # 控制曲线的陡峭度
c = 6                           # 水平位移

# Sigmoid函数定义
s_curve = 3.0 + (6.0 - 3.0) / (1 + np.exp(-a * (t - c)))
max_speed = 4.0+(6.0-4.0)/(1 + np.exp(-a * (38 - 39)))
print("mass:", max_speed)

# 绘制S曲线
plt.plot(t, s_curve, label="S-Curve (Sigmoid)")
plt.title("S-Curve Example (Sigmoid)")
plt.xlabel("Time (t)")
plt.ylabel("Value")
plt.legend()
plt.grid()
plt.show()
