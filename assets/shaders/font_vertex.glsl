#version 460 core
layout (location = 0) in vec4 lVertex;

out vec2 outTexCoords;

uniform mat4 uProjection;

void main() {
    gl_Position = uProjection * vec4(lVertex.xy, 1.4, 1.0);
    outTexCoords = lVertex.zw;
}  
