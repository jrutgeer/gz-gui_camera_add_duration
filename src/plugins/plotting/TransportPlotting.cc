/*
 * Copyright (C) 2020 Open Source Robotics Foundation
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
#include <gz/plugin/Register.hh>
#include <gz/utils/ImplPtr.hh>
#include "TransportPlotting.hh"

namespace gz::gui::plugins
{
//////////////////////////////////////////
void TransportPlotting::LoadConfig(const tinyxml2::XMLElement *)
{
  if (this->title.empty())
    this->title = "Transport plotting";
}

//////////////////////////////////////////
TransportPlotting::TransportPlotting() = default;

//////////////////////////////////////////
TransportPlotting::~TransportPlotting() = default;

}  // namespace gz::gui::plugins
// Register this plugin
GZ_ADD_PLUGIN(gz::gui::plugins::TransportPlotting,
              gz::gui::Plugin)
