#pragma once

#include "Atlas/Input.h"

namespace Atlas
{
   class CWindowsInput : public CInput
   {
   protected:
      virtual bool IsKeyPressedImpl(int keycode) override;

      virtual bool IsMouseButtonPressedImpl(int nButton) override;
      virtual std::pair<float, float> GetMousePositionImpl(void) override;
      virtual float GetMouseXImpl(void) override;
      virtual float GetMouseYImpl(void) override;
   };
}