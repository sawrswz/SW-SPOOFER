#include "Drawing.h"
#include <string>

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <random>
#include <csignal>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstreamm
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include <strsafe.h>
#include "font_awesome.cpp"
#pragma comment(lib, "urlmon.lib")

LPCSTR Drawing::lpWindowName = "Spoofer";
ImVec2 Drawing::vWindowSize = { 650, 440 };
ImGuiWindowFlags Drawing::WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize;
bool Drawing::bDraw = true;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

using namespace std;

namespace Tab
{
    static int Tabs = 1;
}

static int tabs = 0;

bool restartpcafterspoof = false;
bool showconsolewhilespoof = true;
bool showconsolewhileclean = false;
char licensekey[255] = "";
char expiredate[255] = "01.01.2055";

void Drawing::Draw()
{
	if (isActive())
	{
		
		ImGui::SetNextWindowSize(vWindowSize);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
            if (tabs == 0)
            {
                if (ImGui::BeginChild("##LoginChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true)) {

                    ImGui::SetNextItemWidth(320);
                    ImGui::SetCursorPos({ 160, 130 });
                    ImGui::InputText("##Licensekey", licensekey, IM_ARRAYSIZE(licensekey));
                    ImGui::SetCursorPos({ 240, 175 });
                    if (ImGui::Button(ICON_FA_ARROW_ROTATE_RIGHT " Login", ImVec2(160, 45))) {
                        tabs = 1;
                        /*if (licensekey == "999")
                        {
                            tabs = 1;
                        }
                        else
                        {
                            tabs = 0;
                        }*/
                    }
                }
                
            }
            if (tabs == 1)
            {
                if (ImGui::BeginChild("##LeftSide", ImVec2(190, ImGui::GetContentRegionAvail().y), true)) {
                    if (ImGui::Button(ICON_FA_HOUSE " Home", ImVec2(ImGui::GetContentRegionAvail().x, 45)))
                        Tab::Tabs = 1;
                    if (ImGui::Button(ICON_FA_ROCKET " Spoofer", ImVec2(ImGui::GetContentRegionAvail().x, 45)))
                        Tab::Tabs = 2;
                    if (ImGui::Button(ICON_FA_CIRCLE_XMARK " Cleaner", ImVec2(ImGui::GetContentRegionAvail().x, 45)))
                        Tab::Tabs = 3;
                    if (ImGui::Button(ICON_FA_CIRCLE_USER " Account", ImVec2(ImGui::GetContentRegionAvail().x, 45)))
                        Tab::Tabs = 4;
                    ImGui::SetCursorPos({ 10, 326 });
                    ImGui::Text("Expire Date: ");
                    ImGui::SetCursorPos({ 10, 343 });
                    ImGui::TextDisabled(expiredate);
                    ImGui::SetCursorPos({ 10, 366 });
                    if (ImGui::Button(ICON_FA_ARROW_LEFT " Log Out", ImVec2(ImGui::GetContentRegionAvail().x, 27))) {
                        tabs = 0;
                    }

                    ImGui::EndChild();
                }
                {
                    ImGui::SameLine(0);
                    ImGui::Separator();
                    ImGui::SameLine();
                }
                if (ImGui::BeginChild("##RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true)) {
                    if (Tab::Tabs == 1)
                    {
                        ImGui::Text("News:");
                        ImGui::SetCursorPos({ 15, 30 });
                        if (ImGui::BeginChild("##SpooferNewsChild", ImVec2(398, 250), true)) {
                            ImGui::Text("Added: ");
                            ImGui::TextDisabled("FiveM Cleaner");
                            ImGui::Spacing();
                            ImGui::Text("News: ");
                            ImGui::TextDisabled("New Discord");
                            ImGui::Spacing();
                            ImGui::Text("Added: ");
                            ImGui::TextDisabled("Valorant Cleaner");
                            ImGui::Spacing();
                            ImGui::Text("Undetected: ");
                            ImGui::TextDisabled("Bypassing and Undetected for every Anti Cheat");
                            ImGui::Spacing();
                            ImGui::Text("Updated: ");
                            ImGui::TextDisabled("EAC Bypassing and Faster Loading and Spoofing - Yesterday");

                            ImGui::EndChild();
                        }
                        ImGui::SetCursorPos({ 120, 340 });
                        if (ImGui::Button(ICON_FA_ARROW_ROTATE_RIGHT " Update Spoofer", ImVec2(160, 45))) {

                        }
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Its Already Up to Date");
                            ImGui::PopTextWrapPos();

                            ImGui::EndTooltip();
                        }
                    }
                    else if (Tab::Tabs == 2)
                    {
                        ImGui::Text(ICON_FA_GEAR "Spoofer");
                        ImGui::SetCursorPos({ 15, 225 });
                        if (ImGui::Button(ICON_FA_CIRCLE_CHECK " Spoof Eac", ImVec2(190, 45))) {

                        }
                        ImGui::SetCursorPos({ 225, 225 });
                        if (ImGui::Button(ICON_FA_SHIELD " Spoof FiveM", ImVec2(190, 45))) {

                        }
                        ImGui::SetCursorPos({ 15, 280 });
                        if (ImGui::Button(ICON_FA_LEAF " Spoof Other Anti Cheats", ImVec2(400, 45))) {

                        }
                        ImGui::SetCursorPos({ 15, 340 });
                        ImGui::Checkbox("Restart PC after Spoofing", &restartpcafterspoof);
                        ImGui::SameLine();
                        ImGui::TextDisabled("(?)");
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("For Best Spoof Possible");
                            ImGui::PopTextWrapPos();

                            ImGui::EndTooltip();
                        }
                        ImGui::SetCursorPos({ 225, 340 });
                        ImGui::Checkbox("Show Spoofing Console", &showconsolewhilespoof);
                        ImGui::SameLine();
                        ImGui::TextDisabled("(?)");
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Shows the Console");
                            ImGui::PopTextWrapPos();

                            ImGui::EndTooltip();
                        }
                        if (showconsolewhilespoof) {
                            ImGui::SetCursorPos({ 15, 30 });
                            if (ImGui::BeginChild("##SpooferConsoleChild", ImVec2(398, 185), true)) {
                                ImGui::Text(ICON_FA_LIST " Spoofer Console:");
                                ImGui::Text("Spoofing...");
                                ImGui::TextDisabled("Takes about 30 Seconds to Finish");
                                ImGui::Spacing();
                                ImGui::Text("Saving Logs in C:\\Username\\Spoofername\\SpooferLogs.txt...");
                                ImGui::TextDisabled("Finishing Soon");
                                ImGui::Spacing();
                                ImGui::Text("Thanks for Spoofing");
                                ImGui::TextDisabled("You can Close the Window now");
                            }
                        }
                    }
                    else if (Tab::Tabs == 3)
                    {
                        ImGui::SetCursorPos({ 20, 10 });
                        if (ImGui::Button(ICON_FA_GAMEPAD " Clean Apex Legends", ImVec2(190, 45))) {
                            Beep(150, 300);
                            //https://cdn.discordapp.com/attachments/1016719958014689291/1030452889795166238/ApexLegendsCleaner.bat
                        }
                        ImGui::SetCursorPos({ 225, 10 });
                        if (ImGui::Button(ICON_FA_ATOM " Clean Fallout 76", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 20, 65 });
                        if (ImGui::Button(ICON_FA_DATABASE " Clean Call Of Duty", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 225, 65 });
                        if (ImGui::Button(ICON_FA_DATABASE " Clean Splitgate", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 20, 120 });
                        if (ImGui::Button(ICON_FA_BUS " Clean Fortnite", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 225, 120 });
                        if (ImGui::Button(ICON_FA_BUS " Clean Bombergrounds", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 20, 175 });
                        if (ImGui::Button(ICON_FA_MAGNET " Clean Rust", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 225, 175 });
                        if (ImGui::Button(ICON_FA_MAGNET " Clean R6S", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 20, 230 });
                        if (ImGui::Button(ICON_FA_CROSSHAIRS " Clean Valorant", ImVec2(190, 45))) {
                            Beep(150, 300);
                            //https://cdn.discordapp.com/attachments/1026120178074914936/1026120237688557588/valorant-cleaner.exe
                        }
                        ImGui::SetCursorPos({ 225, 230 });
                        if (ImGui::Button(ICON_FA_CROSSHAIRS " Clean Shatterline", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 20, 285 });
                        if (ImGui::Button(ICON_FA_CIRCLE_MINUS " Clean FiveM", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 225, 285 });
                        if (ImGui::Button(ICON_FA_CIRCLE_MINUS " Clean RageMP", ImVec2(190, 45))) {
                            Beep(150, 300);
                        }
                        ImGui::SetCursorPos({ 120, 350 });
                        ImGui::Checkbox("Show Cleaner Console", &showconsolewhileclean);
                        ImGui::SameLine();
                        ImGui::TextDisabled("(?)");
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Shows the Console while Cleaning");
                            ImGui::PopTextWrapPos();

                            ImGui::EndTooltip();
                        }
                        if (showconsolewhileclean == true) {
                            ImGui::SetNextWindowSize({ 500, 300 });
                            ImGui::Begin("Cleaning Console", &bDraw, WindowFlags);
                            {
                                if (ImGui::BeginChild("##CleaningConsoleChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true)) {
                                    ImGui::Text(ICON_FA_CIRCLE_XMARK " Stoping Processes...");
                                    ImGui::TextDisabled("Steam, Origin, FiveM etc...");
                                    ImGui::Spacing();
                                    ImGui::Text(ICON_FA_CIRCLE_XMARK " Deleting Traces Files...");
                                    ImGui::TextDisabled("Thats the Point of a Cleaner");
                                    ImGui::Spacing();
                                    ImGui::Text(ICON_FA_CIRCLE_CHECK " Finished Cleaning");
                                    ImGui::TextDisabled("All Ready and Set");

                                    ImGui::EndChild();
                                }


                            }
                            ImGui::End();
                        }
                    }
                    else if (Tab::Tabs == 4)
                    {
                        ImGui::SetCursorPos({ 150, 10 });
                        ImGui::Text("Username: ");
                        ImGui::SetCursorPos({ 150, 30 });
                        ImGui::TextDisabled("Kakao");
                        ImGui::SetCursorPos({ 150, 70 });
                        ImGui::Text("Expire Date: ");
                        ImGui::SetCursorPos({ 150, 90 });
                        ImGui::TextDisabled(expiredate);

                        ImGui::SetCursorPos({ 10, 375 });
                        ImGui::Text("Last Update:");
                        ImGui::SameLine();
                        ImGui::TextDisabled("Yesterday");

                    }
                    ImGui::EndChild();
                }
            }
		}
		ImGui::End();
	}

	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
}
