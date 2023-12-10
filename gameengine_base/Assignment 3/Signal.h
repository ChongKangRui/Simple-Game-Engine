#pragma once
#include <functional>
#include <map>

// A signal object may call multiple slots with the
// same signature. You can connect functions to the signal
// which will be called when the emit() method on the
// signal object is invoked. Any argument passed to emit()
// will be passed to the given functions.
namespace GameEngine {
	//! This documentation will briefing the usage of %GameObject. %GameObject is a class that can use to create a game object. 
	//! A signal object may call multiple slots with the same signature.You can connect functions to the signal which will be called when the emit() method on the signal object is invoked.
	//! Any argument passed to emit() will be passed to the given functions.
	template <typename... Args>
	class Signal {
		
	public:
		Signal() = default;
		~Signal() = default;

		//! Copy constructor and assignment create a new signal.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "Signal.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		* Signal<int> s2;
		* Signal<int, bool> s3;
		* Signal<bool, int> s4;
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		Signal(Signal const& /*unused*/) {}

		Signal& operator=(Signal const& other) {
			if (this != &other) {
				disconnect_all();
			}
			return *this;
		}

		//! Move constructor and assignment operator work as expected.
		Signal(Signal&& other) noexcept :
			_slots(std::move(other._slots)),
			_current_id(other._current_id) {}

		Signal& operator=(Signal&& other) noexcept {
			if (this != &other) {
				_slots = std::move(other._slots);
				_current_id = other._current_id;
			}

			return *this;
		}

		//! Connects a std::function to the signal. The returned
		//! value can be used to disconnect the function again.
		//! This function can be use to connect the function to the signal.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		*
		* void Func1(){}
		* 
		* void Func2(int i){}
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		* Signal<int> s2;
		*
		* s1.connect(&Func1);
		* s2.connect(&Func2);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		int connect(std::function<void(Args...)> const& slot) const {
			_slots.insert(std::make_pair(++_current_id, slot));
			return _current_id;
		}

		//! Convenience method to connect a member function of an
		//! object to this Signal.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		*Class Member1{
		* void Func1(){}
		* }
		*
		* 
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		* 
		*
		* s1.connect_member(&Member1, &Member1::Func1());
		* 
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		template <typename T>
		int connect_member(T* inst, void (T::* func)(Args...)) {
			return connect([=](Args... args) {
				(inst->*func)(args...);
				});
		}

		//! Convenience method to connect a const member function
		//! of an object to this Signal.
		//! The usage for this function is the same with previous connect_member.
		template <typename T>
		int connect_member(T* inst, void (T::* func)(Args...) const) {
			return connect([=](Args... args) {
				(inst->*func)(args...);
				});
		}

		//! Disconnects a previously connected function.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* Class Member1{
		* void Func1(){}
		* void Func2(){}
		* }
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		*
		* //id = 0
		* s1.connect_member(&Member1, &Member1::Func1());
		* //id = 1
		* s2.connect_member(&Member1, &Member1::Func2());
		* 
		* //will disconnect the Func1()
		* s1.disconnect(0);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void disconnect(int id) const {
			_slots.erase(id);
		}

		//! Disconnects all previously connected functions.
		//! Disconnects a previously connected function.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* Class Member1{
		* void Func1(){}
		* void Func2(){}
		* }
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		*
		* //id = 0
		* s1.connect_member(&Member1, &Member1::Func1());
		* //id = 1
		* s2.connect_member(&Member1, &Member1::Func2());
		*
		* //will disconnect all the function.
		* s1.disconnect_all();
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void disconnect_all() const {
			_slots.clear();
		}

		//! Calls all connected functions.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* Class Member1{
		* void Func1(){printf("1 \n");}
		* void Func2(){printf("2 \n");}
		* }
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		*
		* //id = 0
		* s1.connect_member(&Member1, &Member1::Func1());
		* //id = 1
		* s2.connect_member(&Member1, &Member1::Func2());
		*
		* //will call all function.
		* //Therefore, it will print 1 and 2
		* s1.emit();
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void emit(Args... p) {
			for (auto const& it : _slots) {
				it.second(p...);
			}
		}

		//! Calls all connected functions except for one.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* Class Member1{
		* void Func1(){printf("1 \n");}
		* void Func2(){printf("2 \n");}
		* }
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		*
		* //id = 0
		* s1.connect_member(&Member1, &Member1::Func1());
		* //id = 1
		* s2.connect_member(&Member1, &Member1::Func2());
		*
		* //will call func1 only
		* //Therefore, it will print 1 only
		* s1.emit_for_all_but_one(1);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void emit_for_all_but_one(int excludedConnectionID, Args... p) {
			for (auto const& it : _slots) {
				if (it.first != excludedConnectionID) {
					it.second(p...);
				}
			}
		}

		//! Calls only one connected function.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* Class Member1{
		* void Func1(){printf("1 \n");}
		* void Func2(){printf("2 \n");}
		* }
		*
		*
		*
		*int main(){
		*
		* //You are able to create different signal with different arguement
		* Signal<> s1;
		*
		* //id = 0
		* s1.connect_member(&Member1, &Member1::Func1());
		* //id = 1
		* s2.connect_member(&Member1, &Member1::Func2());
		*
		* //will call func2 only
		* //Therefore, it will print 2 only
		* s1.emit_for(1);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void emit_for(int connectionID, Args... p) {
			auto const& it = _slots.find(connectionID);
			if (it != _slots.end()) {
				it->second(p...);
			}
		}

	private:
		mutable std::map<int, std::function<void(Args...)>> _slots;
		mutable int                                         _current_id{ 0 };
	};
}