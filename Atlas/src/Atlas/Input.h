#pragma once

#include "Atlas/Core.h"

namespace Atlas
{
   class ATLAS_API CInput
   {
      public:
         inline static bool IsKeyPressed(int keycode) { return m_pInstance->IsKeyPressedImpl(keycode); }

         inline static bool IsMouseButtonPressed(int nButton) { return m_pInstance->IsMouseButtonPressedImpl(nButton); }
         inline static std::pair<float, float> GetMousePosition(void) { return m_pInstance->GetMousePositionImpl(); }
         inline static float GetMouseX(void) { return m_pInstance->GetMouseXImpl(); }
         inline static float GetMouseY(void) { return m_pInstance->GetMouseYImpl(); }
      protected:
         virtual bool IsKeyPressedImpl(int keycode) = 0;

         virtual bool IsMouseButtonPressedImpl(int nButton) = 0;
         virtual std::pair<float,float> GetMousePositionImpl(void) = 0;
         virtual float GetMouseXImpl(void) = 0;
         virtual float GetMouseYImpl(void) = 0;
      private:
         static CInput* m_pInstance;
   };
}