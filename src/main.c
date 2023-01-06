#include <env/input.h>
#include <env/memory.h>
#include <env/print.h>
#include <env/webgl.h>

void
main()
{
  const char* string1 = "Hello, Marmeladka! What's Up at yours bro?";

  int numberToReturn = 4 * 4;

  glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

  const float verts[6] = { -0.5, -0.5, 0.0, 0.5, 0.5, -0.5 };

  const char* vertexShader =
    "#version 300 es\n"
    "precision mediump float;"
    "layout(location = 0) in vec3 a_Position;"
    "layout(location = 1) in vec2 a_TexCoord;"
    "layout(location = 2) in vec3 a_Normal;"
    "out vec4 v_Color;"
    "uniform vec3 u_Offset;"
    "uniform vec3 u_Size;"
    "uniform float u_Aspect;"
    "void main()"
    "{"
    "vec3 offset = u_Offset;"
    "offset.y = u_Offset.y / u_Aspect;"
    "gl_Position = vec4(a_Position * u_Size + offset, 1.0f);"
    "gl_Position.y = gl_Position.y * u_Aspect;"
    "v_Color = vec4(a_TexCoord, 0.5f, 1.0f);"
    "}";
  const char* fragmentShader = "#version 300 es\n"
                               "precision mediump float;"
                               "out vec4 o_Color;"
                               "in vec4 v_Color;"
                               "void main()"
                               "{"
                               "o_Color = v_Color;"
                               "}";

  uint32_t vbo = 0, vao = 0, program = 0;

  vao = glCreateVertexArray();
  glBindVertexArray(vao);
  vbo = glCreateBuffer();
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(
    GL_ARRAY_BUFFER, sizeof(verts), (void*)&verts[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
  glEnableVertexAttribArray(0);

  program = glCreateProgram();
  uint32_t vertShaderID = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertShaderID, vertexShader);
  glCompileShader(vertShaderID);

  uint32_t fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShaderID, fragmentShader);
  glCompileShader(fragShaderID);

  // make a program out of the shaders
  glAttachShader(program, vertShaderID);
  glAttachShader(program, fragShaderID);
  glLinkProgram(program);
  glValidateProgram(program);

  // we don't need the shaders anymore
  glDeleteShader(vertShaderID);
  glDeleteShader(fragShaderID);

  glUseProgram(program);

  printf("%s The number's %d, and char's %c\nAAAAAA THERE ARE DECIMALS ALSO "
         "%f!!!\n",
         string1,
         numberToReturn,
         'a',
         2.5);
}

struct input_t input = {};

void
loop()
{
  env_ig(&input);

  glClear(GL_COLOR_BUFFER_BIT);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  // printf("Mouse is on: %d : %d\n", input.position_x, input.position_y);
  // printf("Mouse delta: %d : %d\n", input.delta_x, input.delta_y);
  // printf("Mouse wheel: %d : %d\n", input.scroll_x, input.scroll_y);
  // printf("Mouse buttons: [%d / %d / %d | %d / %d]\n",
  //        input.buttons[0],
  //        input.buttons[1],
  //        input.buttons[2],
  //        input.buttons[3],
  //        input.buttons[4]);
  // printf("Keyboard: W[%d] S[%d] A[%d] D[%d] Space[%d]\n",
  //        input.keys[87],
  //        input.keys[83],
  //        input.keys[65],
  //        input.keys[68],
  //        input.keys[32]);
}