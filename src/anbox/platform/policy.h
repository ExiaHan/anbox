/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ANBOX_PLATFORM_POLICY_H_
#define ANBOX_PLATFORM_POLICY_H_

#include "anbox/graphics/rect.h"
#include "anbox/wm/window_state.h"

#include <memory>

namespace anbox {
namespace audio {
class Sink;
class Source;
} // namespace audio
namespace wm {
class Window;
} // namespace wm
namespace platform {
class Policy {
 public:
  virtual ~Policy();

  virtual std::shared_ptr<wm::Window> create_window(const anbox::wm::Task::Id &task, const anbox::graphics::Rect &frame, const std::string &title) = 0;

  struct ClipboardData {
    std::string text;
  };

  virtual void set_clipboard_data(const ClipboardData &data) = 0;
  virtual ClipboardData get_clipboard_data() = 0;

  virtual std::shared_ptr<audio::Sink> create_audio_sink() = 0;
  virtual std::shared_ptr<audio::Source> create_audio_source() = 0;
};
}  // namespace wm
}  // namespace anbox

#endif
