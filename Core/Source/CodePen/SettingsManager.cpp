#include "pspch.h"
#include "SettingsManager.h"
#include <fstream>
#include "Log.h"

namespace CodePen {

	SettingsManager& SettingsManager::Get()
	{
		static SettingsManager instance;
		return instance;
	}

	void SettingsManager::Load()
	{
		std::ifstream file("config/config.json");
		if (!file.is_open())
		{
			PS_CORE_WARN("Settings file not found, using defaults.");
			CreateFolder("config");
			std::ofstream file("config/config.json");
			return;
		}

		try
		{
			nlohmann::json j;
			file >> j;
			m_Settings.themeIndex = j.value("themeIndex", 3);
			m_Settings.channelIndex = j.value("channelIndex", 0);
			m_Settings.fontSize = j.value("fontSize", 20);
			m_Settings.recentFiles = j.value("recentFiles", std::vector<std::string>{});
			m_Settings.openFiles = j.value("openFiles", std::vector<std::string>{});
			m_Settings.WindowWidth = j.value("WindowWidth", 1720);
			m_Settings.WindowHeight = j.value("WindowHeight", 1000);
		}
		catch (const std::exception& e)
		{
			PS_CORE_ERROR("Failed to parse settings JSON: {}", e.what());
		}
		PS_CORE_INFO("Settings loaded.");
	}

	void SettingsManager::Save() const
	{
		nlohmann::json j;
		j["themeIndex"] = m_Settings.themeIndex;
		j["channelIndex"] = m_Settings.channelIndex;
		j["fontSize"] = m_Settings.fontSize;
		j["recentFiles"] = m_Settings.recentFiles;
		j["openFiles"] = m_Settings.openFiles;
		j["WindowWidth"] = m_Settings.WindowWidth;
		j["WindowHeight"] = m_Settings.WindowHeight;

		std::ofstream file("config/config.json");
		if (!file)
		{
			PS_CORE_ERROR("Failed to save settings to config/config.json");
			return;
		}
		file << j.dump(4);
		PS_CORE_INFO("Settings saved.");
	}

	void SettingsManager::AddRecentFile(const std::string& filepath)
	{
		auto& recent = m_Settings.recentFiles;

		recent.erase(std::remove(recent.begin(), recent.end(), filepath), recent.end());

		recent.insert(recent.begin(), filepath);
		if (recent.size() > 1024)
		{
			recent.resize(1024);
		}
		Save();
	}

	void SettingsManager::SetOpenFiles(const std::vector<std::string>& files)
	{
		m_Settings.openFiles = files;
		Save();
	}

	void SettingsManager::SetThemeIndex(int index)
	{
		m_Settings.themeIndex = index;
		Save();
	}

	void SettingsManager::SetChannel(int index)
	{
		m_Settings.channelIndex = index;
		Save();
	}

	void SettingsManager::SetFontSize(int size)
	{
		m_Settings.fontSize = size;
		Save();
	}

	void SettingsManager::SetWindowSize(unsigned int width, unsigned int height)
	{
		m_Settings.WindowWidth = width;
		m_Settings.WindowHeight = height;
		Save();
	}

}
