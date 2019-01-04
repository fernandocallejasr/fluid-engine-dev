// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_GFX_METAL_VERTEX_BUFFER_H_
#define INCLUDE_JET_GFX_METAL_VERTEX_BUFFER_H_

#include <jet/macros.h>

#ifdef JET_MACOSX

#include <jet.gfx/gl_common.h>
#include <jet.gfx/vertex_buffer.h>

#include <map>
#include <string>

namespace jet {
namespace gfx {

class MetalPrivateBuffer;
class MetalPrivateDevice;

//!
//! \brief Dynamic vertex buffer implementation for Metal.
//!
//! This class implements Metal version of vertex buffer. This vertex
//! buffer is dynamic, meaning that the contents can be updated dynamically
//! (TODO).
//!
class MetalVertexBuffer final : public VertexBuffer {
 public:
    //! Constructs empty buffer.
    MetalVertexBuffer(MetalPrivateDevice* device);

    //! Destructor.
    virtual ~MetalVertexBuffer();

    //!
    //! Updates the buffer with given vertex array.
    //!
    //! \param vertices Vertex array data.
    //!
    void update(const float* data) override;

    MetalPrivateBuffer* buffer() const;

 private:
    MetalPrivateDevice* _device = nullptr;
    std::unique_ptr<MetalPrivateBuffer> _buffer;

    void onClear() override;

    void onResize(const ShaderPtr& shader, const float* data,
                  size_t numberOfVertices) override;

    void onBind(Renderer* renderer) override;

    void onUnbind(Renderer* renderer) override;
};

//! Shared pointer type for MetalVertexBuffer.
using MetalVertexBufferPtr = std::shared_ptr<MetalVertexBuffer>;

}  // namespace gfx
}  // namespace jet

#endif  // JET_MACOSX

#endif  // INCLUDE_JET_GFX_METAL_VERTEX_BUFFER_H_
