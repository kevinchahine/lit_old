#pragma once

#include <memory>

namespace lit
{
	namespace cl
	{
	class LitServer;

		class CommandLineHandler
		{
		public:
			CommandLineHandler(LitServer & server);
			CommandLineHandler(const CommandLineHandler&) = default;
			CommandLineHandler(CommandLineHandler&&) noexcept = default;
			virtual ~CommandLineHandler() noexcept = default;
			CommandLineHandler& operator=(const CommandLineHandler&) = default;
			CommandLineHandler& operator=(CommandLineHandler&&) noexcept = default;

			void handle(char** argv, int argc);

			LitServer* litServer() { return pLitServer; }

			const LitServer* litServer() const { return pLitServer; }

		private:
			LitServer * pLitServer;
		};
	}
}
