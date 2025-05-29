#pragma once

namespace Atlas
{
    enum class eShaderDataType
    {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4,
        Int, Int2, Int3, Int4, Bool
    };

    static uint32_t ShaderDataTypeSize(eShaderDataType type)
    {
        switch(type)
        {
            case eShaderDataType::Float: return 4;
            case eShaderDataType::Float2: return 4 * 2;
            case eShaderDataType::Float3: return 4 * 3;
            case eShaderDataType::Float4: return 4 * 4;
            case eShaderDataType::Mat3: return 4 * 4 * 3;
            case eShaderDataType::Mat4: return  4 * 4 * 4;
            case eShaderDataType::Int: return 4;
            case eShaderDataType::Int2: return 4 * 2;
            case eShaderDataType::Int3: return 4 * 3;
            case eShaderDataType::Int4: return 4 * 4;
            case eShaderDataType::Bool: return 1;
        }

        AT_ASSERT(true,"Unknow eShaderDataType!!!");
        return 0;
    }

    struct SBufferElement
    {
        std::string m_sName;
        eShaderDataType m_Type;
        uint32_t m_unSize;
        uint32_t m_unOffset;
        bool m_bNormalized;

        SBufferElement() {}

        SBufferElement(eShaderDataType type, const std::string &name, bool bNormalized = false)
            : m_sName(name), m_Type(type), m_unSize(ShaderDataTypeSize(type)), m_unOffset(0), m_bNormalized(bNormalized)
        {

        }

        uint32_t GetComponentCount(void) const
        {
            switch(m_Type)
            {
                case eShaderDataType::Float:     return 1;
                case eShaderDataType::Float2:    return 2;
                case eShaderDataType::Float3:    return 3;
                case eShaderDataType::Float4:    return 4;
                case eShaderDataType::Mat3:      return 3 * 3;
                case eShaderDataType::Mat4:      return  4 * 4;
                case eShaderDataType::Int:       return 1;
                case eShaderDataType::Int2:      return 2;
                case eShaderDataType::Int3:      return 3;
                case eShaderDataType::Int4:      return 4;
                case eShaderDataType::Bool:      return 1;
            }

            AT_ASSERT(true,"Unknown eShaderDataType!!!");
            return 0;
        }
    };

    class CBufferLayout
    {
        public:
            CBufferLayout(void) {}

            CBufferLayout(const std::initializer_list<SBufferElement> &elements)
                : m_Elements(elements)
            {
                CalculateOffsetAndStride();
            }

            inline uint32_t GetStride(void) const { return m_unStride; }
            inline const std::vector<SBufferElement> &GetElements(void) const { return m_Elements; }

            std::vector<SBufferElement>::iterator begin(void) { return m_Elements.begin(); }
            std::vector<SBufferElement>::iterator end(void) { return m_Elements.end(); }
            std::vector<SBufferElement>::const_iterator begin(void) const { return m_Elements.begin(); }
            std::vector<SBufferElement>::const_iterator end(void) const { return m_Elements.end(); }

        private:
            void CalculateOffsetAndStride(void)
            {
                uint32_t offset = 0;
                m_unStride = 0;
                for(auto &element: m_Elements)
                {
                    element.m_unOffset = offset;
                    offset += element.m_unSize;
                    m_unStride += element.m_unSize;
                }
            }

            std::vector<SBufferElement> m_Elements;
            uint32_t m_unStride = 0;
    };

    class CVertexBuffer
    {
        public:
            virtual ~CVertexBuffer(void) {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual const CBufferLayout &GetLayout(void) const = 0;
            virtual void SetLayout(const CBufferLayout &layout) = 0;

            static CVertexBuffer *Create(float *vertices, uint32_t size);
        private:
    };

    class CIndexBuffer
    {
        public:
            virtual ~CIndexBuffer(void) {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual uint32_t GetCount() const = 0;

            static CIndexBuffer *Create(uint32_t *indices, uint32_t size);
        private:
    };
}