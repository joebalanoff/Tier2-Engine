#pragma once

#include "../../core/layer.h"

namespace Tier2 {
	class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent() override;

		void Begin();
		void End();

		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
	};
}