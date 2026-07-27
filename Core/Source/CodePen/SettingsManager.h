#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace CodePen {

	struct AppSettings
	{
		int themeIndex = 3;
		int channelIndex = 0;
		int fontSize = 20;

		std::vector<std::string> recentFiles;
		std::vector<std::string> openFiles;

		unsigned int WindowWidth = 1720, WindowHeight = 1000;
	};

	class SettingsManager
	{
	public:
		static SettingsManager& Get();

		void Load();
		void Save() const;

		AppSettings& GetSettings() { return m_Settings; }

		void AddRecentFile(const std::string& filepath);
		void SetOpenFiles(const std::vector<std::string>& files);
		void SetThemeIndex(int index);
		void SetChannel(int index);
		void SetFontSize(int size);

		void SetWindowSize(unsigned int width, unsigned int height);
	private:
		SettingsManager() = default;
		~SettingsManager() = default;
		AppSettings m_Settings;
	};

}
