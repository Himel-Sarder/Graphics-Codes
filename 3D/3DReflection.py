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

# Reflection across XY plane
reflection_matrix = np.array([
[1,0,0],
[0,1,0],
[0,0,-1]
])

reflected_cube = cube.dot(reflection_matrix)

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
    pts = cube[edge]
    ax.plot(pts[:,0], pts[:,1], pts[:,2], color='blue')

# Reflected cube
for edge in edges:
    pts = reflected_cube[edge]
    ax.plot(pts[:,0], pts[:,1], pts[:,2], color='red')

ax.set_xlabel("X Axis")
ax.set_ylabel("Y Axis")
ax.set_zlabel("Z Axis")
ax.set_title("3D Reflection Transformation")

plt.show()