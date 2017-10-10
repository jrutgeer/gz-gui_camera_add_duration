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

#ifndef IGNITION_GUI_VECTOR3DWIDGET_HH_
#define IGNITION_GUI_VECTOR3DWIDGET_HH_

#include <memory>
#include <string>

#include "ignition/gui/qt.h"
#include "ignition/gui/PropertyWidget.hh"
#include "ignition/gui/System.hh"

namespace ignition
{
  namespace gui
  {
    class Vector3dWidgetPrivate;

    /// \brief A widget which holds a vector 3d property.
    class IGNITION_GUI_VISIBLE Vector3dWidget : public PropertyWidget
    {
      Q_OBJECT

      /// \brief Constructor
      /// \param[in] _key Property key value, such as "axis". Unlike other
      /// widgets, the key is not displayed in this widget, it is only used to
      /// set a range.
      public: Vector3dWidget(const std::string &_key);

      /// \brief Destructor
      public: ~Vector3dWidget();

      /// \brief Inherited from PropertyWidget.
      ///
      /// Value will be handled if it holds a math::Vector3d value.
      ///
      /// An input can be constructed as follows:
      /// QVariant value = QVariant::fromValue(ignition::math::Vector3d::Zero);
      ///
      /// \param[in] _value New value.
      /// \return True if succesfull.
      public: bool SetValue(const QVariant _value);

      /// \brief Inherited from PropertyWidget.
      ///
      /// Returns a variant containing the widget's current math::Vector3d
      /// value.
      ///
      /// A pose value can be retrieved as follows:
      /// auto value = this->Value().value<ignition::math::Vector3d>();
      ///
      /// \return Widget's current value.
      public: QVariant Value() const;

      /// \brief Callback when the preset has changed.
      /// \param[in] _index Index of the chosen preset.
      private slots: void OnPresetChanged(const int _index);

      /// \internal
      /// \brief Pointer to private data.
      private: std::unique_ptr<Vector3dWidgetPrivate> dataPtr;
    };
  }
}
#endif
