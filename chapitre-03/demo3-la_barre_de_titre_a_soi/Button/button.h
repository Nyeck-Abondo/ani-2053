#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKMath/NKMath.h"

namespace nkentseu {
    using namespace math;

    enum ComponentType {
        CROSS,
        MAXIMIZE,
        MINIMIZE,
        LOGO,
    };

    enum ComponentState {
        NONE,
        HOVER,
        CLICKED,
    };

    class Button {
        protected :
        RECT buttonSize;
        NkRect2i size;
        ComponentState state;

        public :

        Button(NkRect2i s) {
            size = s;
            buttonSize = {s.x, s.y, s.x + s.w, s.y + s.h};
            logger.Info("[button] size : {0}", size);
            state = ComponentState::NONE;
        }

        RECT GetButtonsize() { return buttonSize; }
        NkRect2i GetSize() { return size; }

        void SetState(ComponentState st) { state = st;}

        bool IsInside(NkVec2 mousePos);
        bool IsClicked(NkEvent& e);
        void Update(NkEvent* event);

        ComponentState GetState() { return state; }

        virtual void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) = 0;
        virtual ComponentType GetType() = 0;
    };

    class CrossBtn : public Button {
        private:
        ComponentType type;

        public:
        CrossBtn(NkRect2i s) : Button(s), type(ComponentType::CROSS) { }
        ~CrossBtn() = default;

        void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

        ComponentType GetType() override { return type; }
    };

    /**
     * @brief
     */
    class MaxBtn : public Button {
        private:
        ComponentType type;

        public:
        MaxBtn(NkRect2i s) : Button(s), type(ComponentType::MAXIMIZE) { }
        ~MaxBtn() = default;

        void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

        ComponentType GetType() override { return type; }
    };

    class MinBtn : public Button {
    private:
        ComponentType type;

        public:
        MinBtn(NkRect2i s) : Button(s), type(ComponentType::MINIMIZE) { }
        ~MinBtn() = default;

        void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

        ComponentType GetType() override { return type; }
    };
    
} // namespace nkentseu