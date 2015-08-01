

namespace WIN32TEST {

class Application
{
public:
    Application();
    ~Application();

public:  // public typdefs

public: // class helpers
    static void launchApp();

private: // internal typedef
    typedef void    *Process;

private: // internal static helpers
    static Process launch();
};

} // namespace WIN32TEST