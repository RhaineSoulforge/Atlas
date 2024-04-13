#pragma once

#include <vector>

namespace Atlas
{
    enum class eCShaderDataType
    {
        None = 0, Float, Float2, Float3, Float4,
        Int, Int2, Int3, Int4, Mat3, Mat4, Bool
    };

    static uint32_t ShaderDataTypeSize(eCShaderDataType type)
    {
        switch(type)
        {
            case(eCShaderDataType::Float): return 4;
            case(eCShaderDataType::Float2): return 8;
            case(eCShaderDataType::Float3): return 12;
            case(eCShaderDataType::Float4): return 16;
            case(eCShaderDataType::Int): return 4;
            case(eCShaderDataType::Int2): return 8;
            case(eCShaderDataType::Int3): return 12;
            case(eCShaderDataType::Int4): return 16;
            case(eCShaderDataType::Mat3): return 36;
            case(eCShaderDataType::Mat4): return 64;
            case(eCShaderDataType::Bool): return 1;
        };

        AT_ASSERT(false,"Unknow ShaderDataType!");
        return 0;
    }

    struct SBufferElement
    {
        std::string m_sName;
        eCShaderDataType m_sdtType;
        uint32_t m_unOffset;
        uint32_t m_unSize;
        bool m_bNormalized;

        SBufferElement() {}

        SBufferElement(eCShaderDataType type, std::string name, bool bNormalized = false)
            :m_sName(name), m_sdtType(type),m_unOffset(0),
             m_unSize(ShaderDataTypeSize(type)),
             m_bNormalized(bNormalized)
        {
        }

        uint32_t GetComponentCount(void) const
        {
            switch(m_sdtType)
            {
                case(eCShaderDataType::Float): return 1;
                case(eCShaderDataType::Float2): return 2;
                case(eCShaderDataType::Float3): return 3;
                case(eCShaderDataType::Float4): return 4;
                case(eCShaderDataType::Int): return 1;
                case(eCShaderDataType::Int2): return 2;
                case(eCShaderDataType::Int3): return 3;
                case(eCShaderDataType::Int4): return 4;
                case(eCShaderDataType::Mat3): return 9;
                case(eCShaderDataType::Mat4): return 16;
                case(eCShaderDataType::Bool): return 1;
            };

            AT_ASSERT(false,"Unknow ShaderDataType!");
            return 0;
        }
    };

    class CBufferLayout
    {
        public:
            CBufferLayout() {}

            CBufferLayout(const std::initializer_list<SBufferElement> &elements)
                :m_vElements(elements)
            {
                CalculateOffsetAndStride();
            }

            inline const std::vector<SBufferElement> &GetElements(void) const { return m_vElements; }

            virtual std::vector<SBufferElement>::iterator begin(void) { return m_vElements.begin(); }
            virtual std::vector<SBufferElement>::iterator end(void) { return m_vElements.end(); }

            virtual std::vector<SBufferElement>::const_iterator begin(void) const { return m_vElements.begin(); }
            virtual std::vector<SBufferElement>::const_iterator end(void) const { return m_vElements.end(); }

            inline virtual uint32_t GetStride(void) const { return m_unStride; }
        private:
            void CalculateOffsetAndStride(void)
            {
                uint32_t offset = 0;
                for(auto &element : m_vElements)
                {
                    element.m_unOffset = offset;
                    offset += element.m_unSize;
                    m_unStride += element.m_unSize;
                }
            }
        private:
            std::vector<SBufferElement> m_vElements;
            uint32_t m_unStride;
    };

    class CVertexBuffer
    {
        public:
            virtual ~CVertexBuffer() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual const CBufferLayout &GetLayout(void) const = 0;
            virtual void SetLayout(const CBufferLayout &layout) = 0;

            static CVertexBuffer *Create(float *vertices, uint32_t size);
    };

    class CIndexBuffer
    {
        public:
            virtual ~CIndexBuffer() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual uint32_t GetCount(void) const = 0;

            static CIndexBuffer *Create(uint32_t *indicies, uint32_t count);
    };
}
