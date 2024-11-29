#ifndef AIMODEL_HPP
#define AIMODEL_HPP

class AiModel {
  public:
    AiModel();
    int train();
    int load();
    ~AiModel() = default;
};

#endif // AIMODEL_HPP
