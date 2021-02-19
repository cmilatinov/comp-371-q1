#version 330

const vec3 toLight1 = normalize(vec3(0, 1, 4));
const vec3 toLight2 = normalize(vec3(0, -1, -4));

in vec3 pass_normal;

out vec4 colour;

uniform vec3 modelColor;

void main() {
	float brightness1 = max(dot(toLight1, normalize(pass_normal)), 0.1);
	float brightness2 = max(dot(toLight2, normalize(pass_normal)), 0.1);
	colour = vec4(modelColor * (brightness1 + brightness2), 1.0f);
}