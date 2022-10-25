// Code adapted from www.learnopengl.com, www.glfw.org

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_interpolation.hpp>

#include "shader.h"

int main(void)
{
	//++++create a glfw window+++++++++++++++++++++++++++++++++++++++
	GLFWwindow* window;

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
    GLfloat firstTriangle[] = {
		 //position data,      colour data
        -0.9f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// Left 
        -0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Right
        -0.45f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Top 
    };
    GLfloat secondTriangle[] = {
         0.0f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,// Left
         0.9f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,// Right
         0.45f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,// Top 
    };

	//ExeOne
	GLfloat exeOnefirstTriangle[] = {
		//position data,      colour data
	   -1.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// Left 
	   -0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Right
	   -0.45f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Top 
	};
	GLfloat exeOnesecondTriangle[] = {
		 0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Left
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 
		 
		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 
		 1.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// TopRight			//Exe 2
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
	};

	GLfloat exeFiveSquareOne[] = {
		 0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Left
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 

		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 
		 1.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// TopRight			//Exe 2
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
	};

	GLfloat exeFiveSquareTwo[] = {
		 0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Left
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 

		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 
		 1.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// TopRight			//Exe 2
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
	};

	GLfloat exeFiveSquareThree[] = {
		 0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Left
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 

		 0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Top 
		 1.0f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// TopRight			//Exe 2
		 1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,// Right
	};

	GLuint VBOs[2], VAOs[2];
	glGenVertexArrays(2, VAOs); // the address-of operator (&) is not needed here, as the array name is a pointer type
	glGenBuffers(2, VBOs);

    // ================================
    // First Triangle setup
    // ===============================
    glBindVertexArray(VAOs[0]); 
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(exeOnefirstTriangle), exeOnefirstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);	// Vertex attributes stay the same, note that the stride is 6*sizeof(GLloat)			
	glEnableVertexAttribArray(0);  // set attribute index of the position attribute to 0 in the vertex shader
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); // Color attribute
	glEnableVertexAttribArray(1);
   
    glBindVertexArray(0);
    // ================================
    // Second Triangle setup
    // ===============================
    glBindVertexArray(VAOs[1]);	// Note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// And a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(exeOnesecondTriangle), exeOnesecondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);	// Vertex attributes stay the same	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); // Color attribute
	glEnableVertexAttribArray(1);
	
    glBindVertexArray(0);

	//++++++++++Build and compile shader program+++++++++++++++++++++
	GLuint shaderProgram = initShader("vert.glsl","frag.glsl");

	//++++++++++++++++++++++++++++++++++++++++++++++
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		GLint transformLoc;

		// Draw the first Triangle
		glm::mat4 transform;
		transform = glm::translate(transform, glm::vec3(-0.7f, 0.0f, 0.0f));		//Exe 4
		transform = glm::rotate(transform, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		transform = glm::translate(transform, glm::vec3(0.5f, 0.0f, 0.0f));			//Exe 4

		/*GLfloat dx = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 0.5);			//Exe 3
		transform = glm::translate(transform, glm::vec3(0.0f, dx, 0.0f));*/	
		
		// Get matrix's uniform location and set matrix
		transformLoc = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Draw the second Triangle
		transform = glm::mat4();
		transform = glm::translate(transform, glm::vec3(0.7f, 0.0f, 0.0f));			//Exe 4
		transform = glm::rotate(transform, -(GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.0f, 0.0f, 1.0f));		//Exe 2
		transform = glm::translate(transform, glm::vec3(-0.5f, 0.0f, 0.0f));		//Exe 4

		/*GLfloat dx2 = (GLfloat)(glm::abs(glm::sin(glfwGetTime())) * 0.5);			//Exe 3
		transform = glm::translate(transform, glm::vec3(dx2, 0.0f, 0.0f));*/
		
		// Get matrix's uniform location and set matrix
		transformLoc = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);

	glfwTerminate();
	return 0;
}