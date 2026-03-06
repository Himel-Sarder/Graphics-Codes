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

# Translation values
tx, ty, tz = 2, 2, 1

# Translated cube
translated_cube = cube + np.array([tx, ty, tz])

# Cube edges
edges = [
    [0,1],[1,2],[2,3],[3,0],
    [4,5],[5,6],[6,7],[7,4],
    [0,4],[1,5],[2,6],[3,7]
]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot original cube
for edge in edges:
    points = cube[edge]
    ax.plot(points[:,0], points[:,1], points[:,2], color='blue')

# Plot translated cube
for edge in edges:
    points = translated_cube[edge]
    ax.plot(points[:,0], points[:,1], points[:,2], color='red')

# Labels
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')

ax.set_title("3D Translation Transformation")

plt.show()