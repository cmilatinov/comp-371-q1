#version 330

const vec3 toLight1 = normalize(vec3(0, 1, 3));

in vec3 pass_normal;

out vec4 colour;

uniform vec3 modelColor;

void main() {
	float brightness1 = min(max(dot(toLight1, normalize(pass_normal)), 0.1), 0.9);
	colour = vec4(modelColor * brightness1, 1.0f);
}