//******************************************************************************
/*!
  \file      src/Control/Toggle.h
  \author    J. Bakosi
  \date      Fri Sep 27 09:02:30 2013
  \copyright Copyright 2005-2012, Jozsef Bakosi, All rights reserved.
  \brief     Options and associations
  \details   Options and associations
*/
//******************************************************************************
#ifndef Toggle_h
#define Toggle_h

#include <map>
#include <sstream>

#include <Exception.h>

namespace quinoa {
//! selections
namespace sel {

template< typename Enum >
class Toggle {

  public:
    using EnumType = Enum;     //! Used to access template typename from outside

    //! Lookup group name
    const std::string& group() const {
      return groupname;
    }

    //! Lookup Enum value based on keyword
    Enum value(const std::string keyword) const {
      auto it = values.find(keyword);
      Assert(it != values.end(), ExceptType::FATAL,
            "Cannot find value for keyword \"" + keyword + "\"");
      return it->second;
    }

    //! Lookup option name based on Enum
    const std::string& name(Enum value) const {
      auto it = names.find(value);
      Assert(it != names.end(), ExceptType::FATAL,
             std::string("Cannot find name for value \"") + value + "\"");
      return it->second;
    }

  protected:
    //! Constructor protected: designed to be used only as a base class
    Toggle(const std::string& g,
           const std::map<Enum, std::string>& n,
           const std::map<std::string, Enum>& v) :
      groupname(g), names(n), values(v) {}

    //! Destructor protected: designed to be used only as a base class
    virtual ~Toggle() noexcept = default;

  private:
    //! Don't permit copy constructor
    Toggle(const Toggle&) = delete;
    //! Don't permit copy assigment
    Toggle& operator=(const Toggle&) = delete;
    //! Don't permit move constructor
    Toggle(Toggle&&) = delete;
    //! Don't permit move assigment
    Toggle& operator=(Toggle&&) = delete;

    const std::string groupname;
    const std::map<Enum, std::string>& names;
    const std::map<std::string, Enum>& values;
};

// Operators defined outside of class (still in namespace sel) to equate
// operator scope with that of enums

//! Operator + for adding Enum to a std::string
template< typename Enum >
std::string operator+ (const std::string& lhs, Enum e) {
  std::stringstream ss;
  // Explicit operator call instead of 'ss << lhs', to avoid gcc's 'ambiguous
  // overload'
  operator<<(ss,lhs) << e;
  std::string rhs = ss.str();
  return rhs;
}

//! Operator << for writing Enum to output streams
template< typename Enum, typename Ch, typename Tr >
std::basic_ostream<Ch,Tr>& operator<< (std::basic_ostream<Ch,Tr>& os,
                                       const Enum& e) {
  os << static_cast<unsigned int>(e);
  return os;
}

} // sel::
} // quinoa::

#endif // Toggle_h
