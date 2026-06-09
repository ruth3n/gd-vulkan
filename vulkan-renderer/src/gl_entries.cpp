#define WINGDIAPI
#define APIENTRY __stdcall

#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/wgl.h>
#include <GL/wglext.h>
#include <atomic>
#include <cstdio>
#include <cstdlib>

static std::atomic<GLuint> g_program_id{1};
static std::atomic<GLuint> g_shader_id{1};
static std::atomic<GLuint> g_texture_id{1};
static std::atomic<GLuint> g_buffer_id{1};
static std::atomic<GLuint> g_vao_id{1};
static std::atomic<GLuint> g_fbo_id{1};
static std::atomic<GLuint> g_rbo_id{1};

#define UNIMPLEMENTED() \
fprintf(stderr, "[VkWrapper] NOT IMPLEMENTED: %s\n", __func__)

extern "C" {

    __declspec(dllexport) GLuint WINAPI glCreateProgram() {
        UNIMPLEMENTED();
        return g_program_id++;
    }

    __declspec(dllexport) void WINAPI glShaderSource(
        GLuint shader, GLsizei count,
        const GLchar** string, const GLint* length)
    {
        UNIMPLEMENTED();
    }

    // ── All GL-fucktions ─────────────────────────────────────

    // ── Shader ──────────────────────────────────────────────
    __declspec(dllexport) GLuint WINAPI glCreateShader(GLenum type) {
        UNIMPLEMENTED(); return g_shader_id++;
    }
    __declspec(dllexport) void WINAPI glCompileShader(GLuint shader) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glAttachShader(GLuint program, GLuint shader) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glLinkProgram(GLuint program) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUseProgram(GLuint program) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteShader(GLuint shader) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteProgram(GLuint program) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glGetProgramiv(GLuint program, GLenum pname, GLint* params) {
        UNIMPLEMENTED(); if (params) *params = 1;
    }
    __declspec(dllexport) void WINAPI glGetShaderiv(GLuint shader, GLenum pname, GLint* params) {
        UNIMPLEMENTED(); if (params) *params = 1;
    }
    __declspec(dllexport) void WINAPI glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) {
        UNIMPLEMENTED(); if (length) *length = 0;
    }

    // ── Uniforms ─────────────────────────────────────────────
    __declspec(dllexport) GLint WINAPI glGetUniformLocation(GLuint program, const GLchar* name) {
        UNIMPLEMENTED(); return -1;
    }
    __declspec(dllexport) void WINAPI glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform1i(GLint location, GLint v0) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform1f(GLint location, GLfloat v0) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform2fv(GLint location, GLsizei count, const GLfloat* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform2i(GLint location, GLint v0, GLint v1) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform2iv(GLint location, GLsizei count, const GLint* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform3fv(GLint location, GLsizei count, const GLfloat* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform3iv(GLint location, GLsizei count, const GLint* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform4fv(GLint location, GLsizei count, const GLfloat* value) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glUniform4iv(GLint location, GLsizei count, const GLint* value) {
        UNIMPLEMENTED();
    }

    // ── Textures ─────────────────────────────────────────────
    __declspec(dllexport) void WINAPI glGenTextures(GLsizei n, GLuint* textures) {
        UNIMPLEMENTED();
        for (GLsizei i = 0; i < n; i++) textures[i] = g_texture_id++;
    }
    __declspec(dllexport) void WINAPI glBindTexture(GLenum target, GLuint texture) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glTexParameteri(GLenum target, GLenum pname, GLint param) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glPixelStorei(GLenum pname, GLint param) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glActiveTexture(GLenum texture) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteTextures(GLsizei n, const GLuint* textures) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glGenerateMipmap(GLenum target) {
        UNIMPLEMENTED();
    }

    // ── Buffer Objects ────────────────────────────────────────
    __declspec(dllexport) void WINAPI glGenBuffers(GLsizei n, GLuint* buffers) {
        UNIMPLEMENTED();
        for (GLsizei i = 0; i < n; i++) buffers[i] = g_buffer_id++;
    }
    __declspec(dllexport) void WINAPI glBindBuffer(GLenum target, GLuint buffer) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteBuffers(GLsizei n, const GLuint* buffers) {
        UNIMPLEMENTED();
    }

    // ── Vertex Arrays ─────────────────────────────────────────
    __declspec(dllexport) void WINAPI glGenVertexArrays(GLsizei n, GLuint* arrays) {
        UNIMPLEMENTED();
        for (GLsizei i = 0; i < n; i++) arrays[i] = g_vao_id++;
    }
    __declspec(dllexport) void WINAPI glBindVertexArray(GLuint array) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteVertexArrays(GLsizei n, const GLuint* arrays) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glEnableVertexAttribArray(GLuint index) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDisableVertexAttribArray(GLuint index) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glVertexAttribPointer(GLuint index, GLint size, GLenum type,
                                                            GLboolean normalized, GLsizei stride, const void* pointer)
    {
        UNIMPLEMENTED();
    }

    // ── Draw Calls ────────────────────────────────────────────
    __declspec(dllexport) void WINAPI glDrawArrays(GLenum mode, GLint first, GLsizei count) {
        UNIMPLEMENTED();
    }

    // ── Render State ──────────────────────────────────────────
    __declspec(dllexport) void WINAPI glClear(GLbitfield mask) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glClearDepth(GLdouble depth) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glEnable(GLenum cap) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDisable(GLenum cap) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glBlendFunc(GLenum sfactor, GLenum dfactor) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glBlendEquation(GLenum mode) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDepthFunc(GLenum func) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glGetBooleanv(GLenum pname, GLboolean* data) {
        UNIMPLEMENTED(); if (data) *data = GL_FALSE;
    }
    __declspec(dllexport) void WINAPI glHint(GLenum target, GLenum mode) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glPointSize(GLfloat size) {
        UNIMPLEMENTED();
    }

    // ── Framebuffer Objects ───────────────────────────────────
    __declspec(dllexport) void WINAPI glGenFramebuffers(GLsizei n, GLuint* framebuffers) {
        UNIMPLEMENTED();
        for (GLsizei i = 0; i < n; i++) framebuffers[i] = g_fbo_id++;
    }
    __declspec(dllexport) void WINAPI glBindFramebuffer(GLenum target, GLuint framebuffer) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glFramebufferRenderbuffer(GLenum target, GLenum attachment,
                                                                GLenum renderbuffertarget, GLuint renderbuffer)
    {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) {
        UNIMPLEMENTED();
        for (GLsizei i = 0; i < n; i++) renderbuffers[i] = g_rbo_id++;
    }
    __declspec(dllexport) void WINAPI glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glRenderbufferStorage(GLenum target, GLenum internalformat,
                                                            GLsizei width, GLsizei height)
    {
        UNIMPLEMENTED();
    }
    __declspec(dllexport) void WINAPI glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) {
        UNIMPLEMENTED();
    }
    // ── Requerement so GD opens a window ──

    __declspec(dllexport) void WINAPI glTexImage2D(
        GLenum target, GLint level, GLint internalformat,
        GLsizei width, GLsizei height, GLint border,
        GLenum format, GLenum type, const void* pixels)
    {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glTexSubImage2D(
        GLenum target, GLint level,
        GLint xoffset, GLint yoffset,
        GLsizei width, GLsizei height,
        GLenum format, GLenum type, const void* pixels)
    {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glGetIntegerv(GLenum pname, GLint* data) {
        UNIMPLEMENTED(); if (data) *data = 0;
    }

    __declspec(dllexport) void WINAPI glGetFloatv(GLenum pname, GLfloat* data) {
        UNIMPLEMENTED(); if (data) *data = 0.0f;
    }

    __declspec(dllexport) GLenum WINAPI glGetError() {
        return GL_NO_ERROR; // no UNIMPLEMENTED log – will be called in tight loops
    }

    __declspec(dllexport) const GLubyte* WINAPI glGetString(GLenum name) {
        switch (name) {
            case GL_VERSION:    return (const GLubyte*)"3.3.0";
            case GL_VENDOR:     return (const GLubyte*)"VkWrapper";
            case GL_RENDERER:   return (const GLubyte*)"Vulkan";
            case GL_EXTENSIONS: return (const GLubyte*)"";
            default:            return (const GLubyte*)"";
        }
    }

    __declspec(dllexport) const GLubyte* WINAPI glGetStringi(GLenum name, GLuint index) {
        return (const GLubyte*)"";
    }

    __declspec(dllexport) void WINAPI glDrawElements(
        GLenum mode, GLsizei count, GLenum type, const void* indices)
    {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glLineWidth(GLfloat width) {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) GLenum WINAPI glCheckFramebufferStatus(GLenum target) {
        return GL_FRAMEBUFFER_COMPLETE;
    }

    __declspec(dllexport) void WINAPI glFramebufferTexture2D(
        GLenum target, GLenum attachment,
        GLenum textarget, GLuint texture, GLint level)
    {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glBindAttribLocation(
        GLuint program, GLuint index, const GLchar* name)
    {
        UNIMPLEMENTED();
    }

    __declspec(dllexport) void WINAPI glFlush()  { UNIMPLEMENTED(); }
    __declspec(dllexport) void WINAPI glFinish() { UNIMPLEMENTED(); }

    // ── WGL – fake context ──

    __declspec(dllexport) HGLRC WINAPI wglCreateContext(HDC hdc) {
        fprintf(stderr, "[VkWrapper] wglCreateContext\n");
        return (HGLRC)calloc(1, 4096); // 4KB
    }

    __declspec(dllexport) BOOL WINAPI wglDeleteContext(HGLRC hglrc) {
        fprintf(stderr, "[VkWrapper] wglDeleteContext\n");
        if (hglrc) free(hglrc);
        return TRUE;
    }

    __declspec(dllexport) BOOL WINAPI wglMakeCurrent(HDC hdc, HGLRC hglrc) {
        fprintf(stderr, "[VkWrapper] wglMakeCurrent\n");
        return TRUE;
    }

    __declspec(dllexport) HGLRC WINAPI wglGetCurrentContext() {
        // fake context - shouldnt be 0
        static void* ctx = nullptr;
        if (!ctx) ctx = calloc(1, 4096);
        return (HGLRC)ctx;
    }

    __declspec(dllexport) HDC WINAPI wglGetCurrentDC() {
        fprintf(stderr, "[VkWrapper] wglGetCurrentDC\n");
        return (HDC)1;
    }

    __declspec(dllexport) PROC WINAPI wglGetProcAddress(LPCSTR lpszProc) {
        fprintf(stderr, "[VkWrapper] wglGetProcAddress: %s\n", lpszProc ? lpszProc : "null");
        return nullptr;
    }

    __declspec(dllexport) BOOL WINAPI wglSwapIntervalEXT(int interval) {
        fprintf(stderr, "[VkWrapper] wglSwapIntervalEXT: %d\n", interval);
        return TRUE;
    }
}
