#pragma once

#include "Atlas/Core.h"

namespace Atlas
{
    class CInput
    {
        public:
            inline static bool IsKeyPressed(int keycode) { return m_pInstance->IsKeyPressedImpl(keycode); }

            inline static bool IsMouseButtonPressed(int button) { return m_pInstance->IsMouseButtonPressedImpl(button); }
            inline static std::pair<float,float> GetMousePosition(void) { return m_pInstance->GetMousePositionImpl(); }

        protected:
            virtual bool IsKeyPressedImpl(int keycode) = 0;

            virtual bool IsMouseButtonPressedImpl(int button) = 0;
            virtual std::pair<float,float> GetMousePositionImpl() = 0;

        private:
            static CInput *m_pInstance;
    };
}