/*
	This source file is part of Rigs of Rods
	Copyright 2005-2012 Pierre-Michel Ricordel
	Copyright 2007-2012 Thomas Fischer
	Copyright 2013-2015 Petr Ohlidal

	For more information, see http://www.rigsofrods.com/

	Rigs of Rods is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License version 3, as
	published by the Free Software Foundation.

	Rigs of Rods is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/** 
	@file   GUI_MultiplayerSelector.h
	@author Moncef Ben Slimane
	@date   11/2014
*/

#include "ForwardDeclarations.h"
#include "GUI_MainSelectorLayout.h"


namespace RoR
{

namespace GUI
{

class MainSelector : public MainSelectorLayout
{

public:
	MainSelector(RoR::SkinManager* skin_manager);
	~MainSelector();

	bool IsFinishedSelecting();
	void Show(LoaderType type);
	void Hide();
	bool IsVisible();
	void BackToMenu();
	void Reset();
	void Cancel();

	CacheEntry *GetSelectedEntry() { return m_selected_entry; }
	Skin *GetSelectedSkin() { return m_selected_skin; }
	std::vector<Ogre::String> GetVehicleConfigs() { return m_vehicle_configs; }
	int ConvertType(LoaderType type) { return LoaderType(type); }
private:

	void NotifyWindowButtonPressed(MyGUI::WidgetPtr _sender, const std::string& _name);

	// gui events
	void EventComboAcceptConfigComboBox(MyGUI::ComboBoxPtr _sender, size_t _index);
	void EventComboChangePositionTypeComboBox(MyGUI::ComboBoxPtr _sender, size_t _index);
	void EventKeyButtonPressed_Main(MyGUI::WidgetPtr _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
	void EventListChangePositionModelList(MyGUI::ListPtr _sender, size_t _index);
	void EventListChangePositionModelListAccept(MyGUI::ListPtr _sender, size_t _index);
	void EventMouseButtonClickCancelButton(MyGUI::WidgetPtr _sender);
	void EventMouseButtonClickOkButton(MyGUI::WidgetPtr _sender);
	void EventSearchTextChange(MyGUI::EditBox *_sender);
	void EventSearchTextGotFocus(MyGUI::WidgetPtr _sender, MyGUI::WidgetPtr oldWidget);
	void NotifyWindowChangeCoord(MyGUI::Window* _sender);
	void ResizePreviewImage();
	void BindKeys(bool bind = true);

	// other functions
	void UpdateGuiData();
	void OnCategorySelected(int categoryID);
	void OnEntrySelected(int entryID);
	void OnSelectionDone();
	size_t SearchCompare(Ogre::String searchString, CacheEntry *ce);

	void UpdateControls(CacheEntry *entry);
	void SetPreviewImage(Ogre::String texture);
	void FrameEntered(float dt);

	CacheEntry*                m_selected_entry;
	LoaderType                 m_loader_type;
	Ogre::String               m_preview_image_texture;
	Skin*                      m_selected_skin;
	bool                       m_selection_done;
	bool                       m_ready;
	std::vector<CacheEntry>    m_entries;
	std::vector<Ogre::String>  m_vehicle_configs;
	std::vector<Skin *>        m_current_skins;
	bool                       m_keys_bound;
	float                      m_ready_time;
	float                      m_deltatime_sum;
	RoR::SkinManager*          m_skin_manager;
};

} // namespace GUI

} // namespace RoR
