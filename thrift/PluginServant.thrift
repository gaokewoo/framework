service PluginServant
{
    void initialize(1:i32 level,2:string configuration);
    void prepareForStart();
    void start();
    void active();
    void passive();
    void stop();
    void prepareForUnload();
    void destroy(1:i32 level);
    i32 getState();
}
