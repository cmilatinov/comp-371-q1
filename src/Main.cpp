#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
#include "Camera.h"
#include "Grid.h"
#include "MeshLoader.h"
#include "EntityRenderer.h"
#include "EntityManager.h"

// When debugging, the code will execute from "out/build/x64-Debug/". That last folder will have the name of your configuration.
// We need to go three levels back to the root directory and into "src" before we can see the "Shaders" folder.
// The build directory might be different with other IDEs and OS, just add a preprocessor conditional statement for your case when you encounter it.
// Vertex Shader file path
static const char * vertex_path = "Shaders/shader.vert";
// Fragment Shader file path
static const char * fragment_path = "Shaders/shader.frag";

void create_entities(MeshLoader & loader, EntityManager & entityManager, EntityGroup ** groups) {
    const Mesh * cubeMesh = loader.load_mesh("cube.obj");
    const Mesh * sphereMesh = loader.load_mesh("sphere.obj");
    const Mesh * cylinderMesh = loader.load_mesh("cylinder.obj");

    Entity * cube = (new Entity(cubeMesh))
            ->translate(vec3(-2, 0, 0))
            ->scale(vec3(1, 0.5f, 0.25f));

    Entity * sphere = (new Entity(sphereMesh))
            ->translate(vec3(-4, 0, 0))
            ->scale(vec3(0.25f, 1, 0.25f));

    Entity * axisX = (new Entity(cylinderMesh))
            ->scale(vec3(0.125f, 2.5f, 0.125f))
            ->rotate(vec3(0, 0, -90))
            ->set_color(vec3(1, 0, 0));

    Entity * axisY = (new Entity(cylinderMesh))
            ->scale(vec3(0.125f, 2.5f, 0.125f))
            ->set_color(vec3(0, 1, 0));

    Entity * axisZ = (new Entity(cylinderMesh))
            ->scale(vec3(0.125f, 2.5f, 0.125f))
            ->rotate(vec3(90, 0, 0))
            ->set_color(vec3(0, 0, 1));

    entityManager.add(cube);
    entityManager.add(sphere);
    entityManager.add(axisX);
    entityManager.add(axisY);
    entityManager.add(axisZ);
//    const Mesh * cylinderMesh = loader.load_mesh("cylinder.obj");
}


int main() {
    // Window creation
    Window main_window(1920, 1080);
	int result = main_window.init();
	if (result == 1) {
		// Error creating the GLFW window so terminate early
		return 1;
	}

    // Creates the camera, used as an abstraction to calculate the view matrix
    Camera camera(glm::vec3(0.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.4f, 0.2f, &main_window);

    // Load shader program
	Shader app_shader(vertex_path, fragment_path);
    app_shader.use_shader();
    glUniform3fv(app_shader.get_color_location(), 1, glm::value_ptr(vec3(1, 0, 0)));

	// Init entity renderer and manager, create necessary entities
	EntityRenderer entityRenderer(app_shader);
	EntityManager entityManager;
    MeshLoader loader;

    // The array of models
    EntityGroup * models[5];
    // The selected model
    EntityGroup* selectedModel;

    create_entities(loader, entityManager, models);

    // The default selected model
    selectedModel = models[0];

    // The window's key states
    bool* keys{ main_window.get_keys() };

	// Creates the grid
	Grid grid(glm::vec3(0.f, 0.f, 0.f));

    // Enable depth in our view space
    glEnable(GL_DEPTH_TEST);
    
    // So we can actually see the points in Point polygon mode
    glPointSize(3.f);

    // Hide surfaces facing away from camera
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);

    // Set clear color to white
    glClearColor(0, 0.5f, 0.5f, 1);

	// Loop until window closed
    GLfloat last_time = 0;
	while (!main_window.should_close())
	{
		// Calculate delta time to minimize speed differences on faster CPUs
		GLfloat now = glfwGetTime();
        GLfloat delta_time = now - last_time;
		last_time = now;

		
		// Get user input events
		glfwPollEvents();

        if (keys[GLFW_KEY_1])
        {
            selectedModel = models[0];
        }
        else if (keys[GLFW_KEY_2])
        {
            selectedModel = models[1];
        }
        else if (keys[GLFW_KEY_3])
        {
            selectedModel = models[2];
        }
        else if (keys[GLFW_KEY_4])
        {
            selectedModel = models[3];
        }
        else if (keys[GLFW_KEY_5])
        {
            selectedModel = models[4];
        }

		camera.key_controls(main_window.get_keys(), delta_time, selectedModel);
		camera.mouse_controls(main_window.get_x_change(), main_window.get_y_change(), main_window.get_mouse_buttons(), delta_time);

		// Clear window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render entities
        entityRenderer.render(camera, entityManager);

        glUniformMatrix4fv(app_shader.get_projection_location(), 1, GL_FALSE, glm::value_ptr(camera.calculate_projection()));
        glUniformMatrix4fv(app_shader.get_model_location(), 1, GL_FALSE, glm::value_ptr(mat4(1.0f)));

		// Display the grid
//		grid.render();

		// Stop the shader
		glUseProgram(0);

		// Display the newly rendered buffer in the window
		main_window.swap_buffers();

	}

	return 0;
}