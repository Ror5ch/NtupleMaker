#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithTriggerResults(const edm::Event& event) 
{
    edm::Handle<TriggerResults> trigger_results;
    event.getByToken(trigger_results_token_, trigger_results);

    const int num_triggers_in_data = trigger_results.product()->size();
    edm::TriggerNames triggers_in_data = event.triggerNames(*trigger_results);

    int nt = 0;
    for (const auto& trigger_name : trigger_list_) 
    {
        for (auto idx = 0; idx != num_triggers_in_data; ++idx) 
        {
            string trigger_name_in_data = triggers_in_data.triggerName(idx);
            if (trigger_name_in_data.find(trigger_name) != std::string::npos) 
            {
                event_.trigger_name->push_back(trigger_name_in_data);
                event_.trigger_decision[nt++] = trigger_results.product()->accept(idx);
                break;
            }
        }
    }
    event_.num_triggers = nt;
    assert(event_.num_triggers == static_cast<int>(event_.trigger_name->size()));
}
void NtupleMaker::FillWithFilters(const edm::Event& event)
{
    edm::Handle<TriggerResults> filters;
    event.getByToken(filters_token_, filters);
    edm::TriggerNames filter_names = event.triggerNames(*filters);

    int nf = 0;
    for (unsigned idx = 0; idx < filters->size(); ++idx) 
    {
        string filter_name = filter_names.triggerName(idx);
        // std::cout << filter_name << std::endl;
        if (filter_name.find("Flag") != std::string::npos) 
        {
            event_.filter_name->push_back(filter_name);
            event_.filter_decision[nf++] = filters.product()->accept(idx);
        }
    }
    event_.num_filters = nf;
    assert(event_.num_filters == static_cast<int>(event_.filter_name->size()));
}