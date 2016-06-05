#version 430 core

varying vec2 textureCoord0;

uniform sampler2D diffuse;

in vec4 vNormal;

void main() {
    float intensity = 2.5f;
    vec4 light = normalize(vec4(1.0f, 0.5f, -1.25f, 1.0f));
    gl_FragColor = texture2D(diffuse, textureCoord0) * intensity * max(dot(light, vNormal), 0.1f);
    //vec4(1.0, 0.0, 0.0, 1.0);
}