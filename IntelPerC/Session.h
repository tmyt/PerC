#pragma once

#include<Windows.h>

#include<pxcsession.h>
#include<pxcsmartptr.h>

namespace PerC
{
	namespace PXC
	{
		public ref class Session sealed
		{
		private:
			static Session^ current_;

			PXCSmartPtr<PXCSession> session_;

			Session(){
				auto status = PXCSession_Create(&session_);
				if(status < PXC_STATUS_NO_ERROR){
					throw ref new Platform::Exception(E_FAIL, "Failed to create an SDK session");
				}
			}

		public:
			static property Session^ Current{
				Session^ get(){
					if(current_ == nullptr){
						current_ = ref new Session();
					}
					return current_;
				}
			}
		};
	}
}