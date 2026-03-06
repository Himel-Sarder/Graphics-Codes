import matplotlib.pyplot as plt
import numpy as np

# Original cube vertices
cube = np.array([
    [0,0,0],
    [1,0,0],
    [1,1,0],
    [0,1,0],
    [0,0,1],
    [1,0,1],
    [1,1,1],
    [0,1,1]
])

# Rotation angle (degrees)
theta = np.radians(45)

# Rotation matrix around Z-axis
Rz = np.array([
    [np.cos(theta), -np.sin(theta), 0],
    [np.sin(theta),  np.cos(theta), 0],
    [0, 0, 1]
])

# Rotated cube
rotated_cube = cube.dot(Rz.T)

# Cube edges
edges = [
    [0,1],[1,2],[2,3],[3,0],
    [4,5],[5,6],[6,7],[7,4],
    [0,4],[1,5],[2,6],[3,7]
]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Original cube
for edge in edges:
    points = cube[edge]
    ax.plot(points[:,0], points[:,1], points[:,2], color='blue')

# Rotated cube
for edge in edges:
    points = rotated_cube[edge]
    ax.plot(points[:,0], points[:,1], points[:,2], color='red')

ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')
ax.set_title("3D Rotation Transformation")

plt.show()