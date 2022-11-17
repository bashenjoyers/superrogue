
namespace superrogue::controller::event {

    class IEvent {
    public:
        virtual ~IEvent() {}

        virtual void execute() = 0;
    };
}
