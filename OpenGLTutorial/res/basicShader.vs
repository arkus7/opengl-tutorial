#version 430 core

attribute vec3 position;
attribute vec2 textureCoord;

varying vec2 textureCoord0;

uniform mat4 transformMatrix;
uniform mat4 modelToCameraMatrix;

out vec4 vNormal;

void main()
{
	gl_Position = transformMatrix * vec4(position, 1.0);
	textureCoord0 = textureCoord;
	mat4 normalMatrix = transpose(inverse(modelToCameraMatrix));
	vNormal = normalize (normalMatrix * vec4(position, 1.0));
}