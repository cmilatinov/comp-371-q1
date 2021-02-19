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

    Entity * m_1 = (new Entity(cubeMesh))
            ->translate(vec3(0.2f, 1.3f, 0))
            ->rotate(vec3(0, 0, 45))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * m_2 = (new Entity(cubeMesh))
            ->translate(vec3(-0.2f, 1.3f, 0))
            ->rotate(vec3(0, 0, -45))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * m_3 = (new Entity(sphereMesh))
            ->translate(vec3(0.6f, 1, 0))
            ->scale(vec3(0.25f, 1, 0.25f));
    Entity * m_4 = (new Entity(sphereMesh))
            ->translate(vec3(-0.6f, 1, 0))
            ->scale(vec3(0.25f, 1, 0.25f));

    EntityGroup * letter_m = (new EntityGroup())
            ->translate(vec3(0, 12.5f, -64))
            ->set_color(vec3(0.83f, 0.18f, 0.18f))
            ->add(m_1)
            ->add(m_2)
            ->add(m_3)
            ->add(m_4);


    Entity * i_1 = (new Entity(sphereMesh))
            ->translate(vec3(0, 1, 0))
            ->scale(vec3(0.25f, 1, 0.25f));

    EntityGroup * letter_i = (new EntityGroup())
            ->translate(vec3(0, 0, -64))
            ->set_color(vec3(0.61f, 0.15f, 0.69f))
            ->add(i_1);

    EntityGroup * letter_i2 = (new EntityGroup())
            ->translate(vec3(0, 10, -64))
            ->set_color(vec3(0.48f, 0.12f, 0.64f))
            ->add(i_1);


    Entity * l_1 = (new Entity(sphereMesh))
            ->translate(vec3(-0.5f, 1, 0))
            ->scale(vec3(0.25f, 1, 0.25f));
    Entity * l_2 = (new Entity(cubeMesh))
            ->translate(vec3(0, 0.25f, 0))
            ->scale(vec3(1, 0.5f, 0.25f));

    EntityGroup * letter_l = (new EntityGroup())
            ->translate(vec3(0, 7.5f, -64))
            ->set_color(vec3(0.19f, 0.25f, 0.62f))
            ->add(l_1)
            ->add(l_2);


    Entity * a_1 = (new Entity(cubeMesh))
            ->rotate(vec3(90, 0, 0))
            ->translate(vec3(0, 0.70f, 0))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * a_2 = (new Entity(cubeMesh))
            ->translate(vec3(-0.5f, 0.5f, 0))
            ->rotate(vec3(0, 0, 70))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * a_3 = (new Entity(cubeMesh))
            ->translate(vec3(-0.17f, 1.4f, 0))
            ->rotate(vec3(0, 0, 70))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * a_4 = (new Entity(cubeMesh))
            ->translate(vec3(0.5f, 0.5f, 0))
            ->rotate(vec3(0, 0, -70))
            ->scale(vec3(1, 0.5f, 0.25f));
    Entity * a_5 = (new Entity(cubeMesh))
            ->translate(vec3(0.17f, 1.4f, 0))
            ->rotate(vec3(0, 0, -70))
            ->scale(vec3(1, 0.5f, 0.25f));

    EntityGroup * letter_a = (new EntityGroup())
            ->translate(vec3(0, 5, -64))
            ->set_color(vec3(0.1f, 0.53f, 0.82f))
            ->add(a_1)
            ->add(a_2)
            ->add(a_3)
            ->add(a_4)
            ->add(a_5);


    Entity * t_1 = (new Entity(sphereMesh))
            ->translate(vec3(0, 1, 0))
            ->scale(vec3(0.25f, 1, 0.25f));
    Entity * t_2 = (new Entity(cubeMesh))
            ->translate(vec3(0, 2, 0))
            ->scale(vec3(1, 0.5f, 0.25f));

    EntityGroup * letter_t = (new EntityGroup())
            ->translate(vec3(0, 2.5f, -64))
            ->set_color(vec3(0.98f, 0.75f, 0.18f))
            ->add(t_1)
            ->add(t_2);


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


    entityManager.add(letter_m);
    entityManager.add(letter_i2);
    entityManager.add(letter_l);
    entityManager.add(letter_a);
    entityManager.add(letter_t);
    entityManager.add(letter_i);
    entityManager.add(axisX);
    entityManager.add(axisY);
    entityManager.add(axisZ);

    groups[0] = letter_m;
    groups[1] = letter_i2;
    groups[2] = letter_l;
    groups[3] = letter_a;
    groups[4] = letter_t;
    groups[5] = letter_i;

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
    EntityGroup * models[6];
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
        else if (keys[GLFW_KEY_6])
        {
            selectedModel = models[5];
        }

		camera.key_controls(main_window.get_keys(), delta_time, selectedModel);
		camera.mouse_controls(main_window.get_x_change(), main_window.get_y_change(), main_window.get_mouse_buttons(), delta_time);

		// Clear window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render entities
        entityRenderer.render(camera, entityManager);

        glUniformMatrix4fv(app_shader.get_projection_location(), 1, GL_FALSE, glm::value_ptr(camera.calculate_projection()));
        glUniformMatrix4fv(app_shader.get_model_location(), 1, GL_FALSE, glm::value_ptr(mat4(1.0f)));
        glUniform3fv(app_shader.get_color_location(), 1, glm::value_ptr(vec3(0, 0, 0)));

		// Display the grid
		grid.render();

		// Stop the shader
		glUseProgram(0);

		// Display the newly rendered buffer in the window
		main_window.swap_buffers();

	}

	return 0;
}