// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_WHEEL_H
#define _GXWMM_WHEEL_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <gxwmm/regler.h>
#include <gtkmm/adjustment.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GxWheel GxWheel;
typedef struct _GxWheelClass GxWheelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gxw
{ class Wheel_Class; } // namespace Gxw
namespace Gxw {


class Wheel: public Gxw::Regler {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Wheel CppObjectType;
  typedef Wheel_Class CppClassType;
  typedef GxWheel BaseObjectType;
  typedef GxWheelClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Wheel();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Wheel_Class;
  static CppClassType wheel_class_;

  // noncopyable
  Wheel(const Wheel&);
  Wheel& operator=(const Wheel&);

protected:
  explicit Wheel(const Glib::ConstructParams& construct_params);
  explicit Wheel(GxWheel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GxWheel*       gobj()       { return reinterpret_cast<GxWheel*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GxWheel* gobj() const { return reinterpret_cast<GxWheel*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	Wheel();
	explicit Wheel(Gtk::Adjustment& adjustment);


};

} // namespace Gxw


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gxw::Wheel
   */
  Gxw::Wheel* wrap(GxWheel* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_WHEEL_H */

