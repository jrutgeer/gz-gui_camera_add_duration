/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

#include <ignition/common/Util.hh>
#include <ignition/utilities/ExtraTestMacros.hh>

#include "test_config.h"  // NOLINT(build/include)

#ifdef _MSC_VER
#    define popen _popen
#    define pclose _pclose
#endif

/////////////////////////////////////////////////
std::string custom_exec_str(std::string _cmd)
{
  _cmd += " 2>&1";
  FILE *pipe = popen(_cmd.c_str(), "r");

  if (!pipe)
    return "ERROR";

  char buffer[128];
  std::string result = "";

  while (!feof(pipe))
  {
    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }

  pclose(pipe);
  return result;
}

TEST(CmdLine, version)
{
  std::string cmd = "C:/Jenkins/workspace/ign_gui-pr-win/ws/install/ignition-gui5/lib/ignition/gui5/ign-gui.exe --version -v 4";
  std::string output = custom_exec_str(cmd);
  std::cerr << "Version: " << output << '\n';
}

TEST(CmdLine, list2)
{
  std::string pathstr;
  ignition::common::env("PATH", pathstr, true);
  std::string cmd = "set \"PATH=" + pathstr + "\" && set QT_QPA_PLATFORM_PLUGIN_PATH=C:/vcpkg/installed/x64-windows/plugins/platforms && set QT_QPA_PLATFORM=offscreen " +
    " && C:/Jenkins/workspace/ign_gui-pr-win/ws/install/ignition-gui5/lib/ignition/gui5/ign-gui.exe -v 4 -l";
  std::string output = custom_exec_str(cmd);
  std::cerr << "List2: " << output << '\n';
}

// See https://github.com/ignitionrobotics/ign-gui/issues/75
TEST(CmdLine, list)
{
  std::string ignConfigPath;
  ignition::common::env("IGN_CONFIG_PATH", ignConfigPath, true);
#ifndef _WIN32
  std::string cmd = std::string("IGN_CONFIG_PATH=") + ignConfigPath +
    " ign gui -l";
#else
  std::string pathstr;
  std::string ign = std::string(IGN_PATH) + "/ign.rb";
  ignition::common::env("PATH", pathstr, true);
  std::string cmd = std::string("set IGN_CONFIG_PATH=") + ignConfigPath +
    " && set \"PATH=" + pathstr + "\" && set QT_QPA_PLATFORM_PLUGIN_PATH=C:/vcpkg/installed/x64-windows/plugins/platforms && set QT_QPA_PLATFORM=offscreen "
    + "&& " + ign + " gui -l -v 4";
  std::cerr << "cmd: " << cmd << '\n';
#endif
  std::string output = custom_exec_str(cmd);
  EXPECT_NE(output.find("TopicEcho"), std::string::npos) << output;
  EXPECT_NE(output.find("Publisher"), std::string::npos) << output;

}
