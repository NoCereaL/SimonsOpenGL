// Simon K Moyana

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_interpolation.hpp>
#include <glm/gtc/constants.hpp>

#include "shader.h"

int main(void)
{
	//++++create a glfw window+++++++++++++++++++++++++++++++++++++++
	GLFWwindow* window;
	float angle = 0;
	float time = 0;
	bool clockwise = true;

	if (!glfwInit()) //Initialize the library
		return -1;

	window = glfwCreateWindow(640, 640, "OpenGL Window", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);//Make the window's context current
	
	//++++Initialize GLEW to setup the OpenGL Function pointers+++++++
	glewExperimental = GL_TRUE;
	glewInit();

	//++++Define the viewport dimensions++++++++++++++++++++++++++++
	glViewport(0, 0, 640, 640);

	//++++++++++Set up vertex data (and buffer(s)) and attribute pointers+++++++++
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.0f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeOne[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.5f, 0.5f, 0.0f,	//TopRight
		-0.5f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeTwo[] = {
		0.0f, -0.5f, 0.0f, // Left  
		1.0f, -0.5f, 0.0f, // Right 
		1.0f, 0.5f, 0.0f,	//TopRight
		0.0f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeThree[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.5f, 0.5f, 0.0f,	//TopRight
		-0.5f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeThreeTwo[] = {
		0.0f, -0.5f, 0.0f, // Left  
		1.0f, -0.5f, 0.0f, // Right 
		1.0f, 0.5f, 0.0f,	//TopRight
		0.0f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeFour[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.5f, 0.5f, 0.0f,	//TopRight
		-0.5f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeFive[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.5f, 0.5f, 0.0f,	//TopRight
		-0.5f,  0.5f, 0.0f  // Top   
	};

	GLfloat exeSix[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.5f, 0.5f, 0.0f,	//TopRight
		-0.5f,  0.5f, 0.0f  // Top   
	};

	GLuint indices[] = { // Note that we start from 0!
		0, 1, 2, // First Triangle
		0, 2, 3, // Second Triangle
		0, 3, 4, // Second Triangle
		0, 4, 5 // Second Triangle
	};

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

    // ================================
    // buffer setup
    // ===============================
    glBindVertexArray(VAO); 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(exeSix), exeSix, GL_STATIC_DRAW);
	//This Methiod i
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
		GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0);

	//++++++++++Build and compile shader program+++++++++++++++++++++
	GLuint shaderProgram = initShader("vert.glsl","frag.glsl");

	if (clockwise == false) {
		glfwSetTime(0);
		clockwise = true;
	}

	//++++++++++++++++++++++++++++++++++++++++++++++
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw the first Triangle
		// use shader
		glUseProgram(shaderProgram);

		//+++++++ Define transform matrix (uncomment the transform matrix you want to create)+++++++
		glm::mat4 transform;
	
		/* Translation */
		//transform = glm::translate(transform, glm::vec3(0.5f, 0.0f, 0.0f));

		/* Rotation */
		//transform = glm::rotate(transform, (GLfloat)(3.14), glm::vec3(0.0f, 0.0f, 1.0f));

		/* Scaling */
		//transform = glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.0f));

		/* animation example: triangle rotation */
		//transform = glm::rotate(transform, (GLfloat)(glfwGetTime()*0.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		
		//Exe1 & Exe2
		//transform = glm::rotate(transform, (GLfloat)(glfwGetTime() * 0.5f), glm::vec3(0.0f, 0.0f, -1.0f));

		//Exe3
		/*if ((GLfloat)glfwGetTime() * 0.5f <= 6.28)
		transform = glm::rotate(transform, (GLfloat)(glfwGetTime() * 0.5f), glm::vec3(0.0f, 0.0f, -1.0f));
		else
		transform = glm::rotate(transform, (GLfloat)(2*3.14), glm::vec3(0.0f, 0.0f, 1.0f));*/

		//Exe3AltMethod
		/*if (angle <= 2 * 3.14)
		{
			transform = glm::rotate(transform, (GLfloat)(glfwGetTime() * 0.5f), glm::vec3(0.0f, 0.0f, -1.0f));
			angle = glfwGetTime() * 0.5f;
			std::cout << angle << std::endl;
		}
		else 
		{
			transform = glm::rotate(transform, (GLfloat)(2*3.14), glm::vec3(0.0f, 0.0f, 1.0f));
		}*/

		/* animation example: triangle translation */
		/*if ((GLfloat)glfwGetTime() * 0.5f <= 0.5)
		transform = glm::translate(transform, glm::vec3((GLfloat)glfwGetTime() * 0.5f, 0.0f, 0.0f));
		else
		transform = glm::translate(transform, glm::vec3(0.5f, 0.0f, 0.0f));*/

		//Exe4
		/*time = (GLfloat)glfwGetTime() * 0.5f;
		if (time <= 0.5) {
			transform = glm::translate(transform, glm::vec3((GLfloat)glfwGetTime() * 0.5f, (GLfloat)glfwGetTime() * 0.5f, 0.0f));
		}
		else if (time >= 0.5 && time <= 1.5f) {
			transform = glm::translate(transform, glm::vec3(0.5f, (GLfloat)glfwGetTime() * -0.5f + 1.0f, 0.0f));
		}
		else if (time >= 1.5f && time <= 2.5f) {
			transform = glm::translate(transform, glm::vec3((GLfloat)glfwGetTime() * -0.5f + 2.0f, -0.5f, 0.0f));
		}
		else {
			transform = glm::translate(transform, glm::vec3(-0.5f, -0.5f, 0.0f));
		}*/

		/* animation example:  */
		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime()))*0.5);
		transform = glm::translate(transform, glm::vec3(dx, 0.0f, 0.0f));*/

		//Exe5
		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 1);
		transform = glm::translate(transform, glm::vec3(0.0f, dx - 0.5f, 0.0f));*/

		//Exe5Two
		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 1);
		transform = glm::translate(transform, glm::vec3(dx - 0.5f, 0.0f, 0.0f));*/

		//Exe5Three
		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 1);
		transform = glm::translate(transform, glm::vec3(dx - 0.5f, dx - 0.5f, 0.0f));*/

		//Exe6
		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 2 * 3.14f);
		transform = glm::rotate(transform, dx, glm::vec3(0.0f, 0.0f, -1.0f));*/

		//Exe7
		GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 0.5f);
		transform = glm::scale(transform, glm::vec3(dx + 1.0f, dx + 1.0f, 0.0f));
		

		// Get matrix's uniform location and set matrix
		GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

		// draw object
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
		glBindVertexArray(0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}