#pragma once

#include "Atlas/Input.h"

namespace Atlas
{
    class CWindowsInput : public CInput
    {
        public:

        protected:
            virtual bool IsKeyPressedImpl(int keycode) override;

            virtual bool IsMouseButtonPressedImpl(int button) override;
            virtual std::pair<float,float> GetMousePositionImpl(void) override;

        private:
    };
}