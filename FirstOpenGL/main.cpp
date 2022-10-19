// Simon K Moyana

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

int main(void)
{
	//++++create a glfw window+++++++++++++++++++++++++++++++++++++++
	GLFWwindow* window;

	if (!glfwInit()) //Initialize the library
		return -1;

	window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
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
	glViewport(0, 0, 640, 480);

	//++++++++++Set up vertex data (and buffer(s)) and attribute pointers+++++++++
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		 0.5f, -0.5f, 0.0f, // Right 
		 0.0f,  0.5f, 0.0f,  // Top   
		 - 0.5f+0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f+0.5f, 0.5f, 0.0f, // TopRight 
		 0.0f+0.5f, -0.5f, 0.0f,  // Bottom   
		 0.5f, 0.5f+1, 0.0f, // TopLeft  
		 0.5f, -0.5f+1, 0.0f, // BottomRight 
		 1.0f,  -0.5f+1, 0.0f  // BottomRight   
	};

	//Author: Simon K Moyana
	
	//++++++++++Set up vertex data (and buffer(s)) and attribute pointers+++++++++
	GLfloat verticesTwo[] = {
		-0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, 0.5f, 0.0f, // TopRight 
		 0.0f, -0.5f, 0.0f  // Bottom   
	};

	//++++++++++Set up vertex data (and buffer(s)) and attribute pointers+++++++++
	GLfloat verticesRAT[] = {
		 0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, -0.5f, 0.0f, // BottomRight 
		 1.0f,  -0.5f, 0.0f  // BottomRight   
	};

	//++++++++++Set up vertex data (and buffer(s)) and attribute pointers+++++++++
	GLfloat exeFour[] = {
		 0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, -0.5f, 0.0f, // BottomRight 
		 1.0f,  -0.5f, 0.0f,  // BottomRight   
		 - 0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, 0.5f, 0.0f, // TopRight 
		 0.0f, -0.5f, 0.0f  // Bottom   
	};

	GLfloat exeFive[] = {
		 -0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, 0.5f, 0.0f, // TopRight 
		 0.5f,  -0.5f, 0.0f,  // BottomRight   
		 -0.5f, 0.5f, 0.0f, // TopLeft  
		 -0.5f, -0.5f, 0.0f, // BottomLeft 
		 0.5f, -0.5f, 0.0f  // BottomRight   
	};

	GLfloat exeSix[] = {
		 0.0f, 0.5f, 0.0f, // TopLeft  
		 -1.0f, -0.5f, 0.0f, // TopRight 
		 0.0f,  -0.5f, 0.0f,  // BottomRight   
		 0.0f, 0.5f, 0.0f, // TopLeft  
		 0.0f, -0.5f, 0.0f, // BottomLeft 
		 1.0f, 0.5f, 0.0f  // BottomRight   
	};

	GLfloat exeSeven[] = {
		 0.0f, 0.5f, 0.0f, // TopLeft  
		 1.0f, 0.5f, 0.0f, // TopRight 
		 0.0f,  -0.5f, 0.0f,  // BottomRight   
		 -1.0f, -0.5f, 0.0f, // TopLeft  
	};

	GLfloat exeSevenFive[] = {
		 -0.5f, 0.5f, 0.0f, // TopLeft  
		 0.5f, 0.5f, 0.0f, // TopRight 
		 0.5f,  -0.5f, 0.0f,  // BottomRight   
		 -0.5f, -0.5f, 0.0f, // TopLeft  
	};

	GLfloat exeEight[] = {
		 0.0f, 1.0f, 0.0f, // TopLeft  
		 -0.5f, 0.5f, 0.0f, // TopRight 
		 0.5f,  0.5f, 0.0f,  // BottomRight   
		 0.25f, -0.25f, 0.0f,
		 -0.25f,-0.25f, 0.0f,
		 -0.5f, 0.5f, 0.0f
	};

	GLfloat exeEightTwo[] = {
		 0.0f, 0.5f, 0.0f, // TopLeft  
		 -0.5f, 0.75f, 0.0f, // TopRight 
		 -0.25f, -0.25f, 0.0f,  // BottomRight   
		 0.25f, -0.25f, 0.0f,
		 0.5f, 0.75f, 0.0f,
		 0.0f, 0.5f, 0.0f
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

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(exeEightTwo), exeEightTwo, GL_STATIC_DRAW);

	//This Methiod i
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
		GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)   -- Edited by Simon Moyana

	//++++++++++Build and compile shader program+++++++++++++++++++++
	GLuint shaderProgram = initShader("vert.glsl","frag.glsl");

	//++++++++++++++++++++++++++++++++++++++++++++++
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw all the points defined in vertices
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		
		//glDrawArrays(GL_TRIANGLES, 0, 9);			//Enable this Method and disable one bellow to draw triangles without indexed rendering

		glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);
	
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