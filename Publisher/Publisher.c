#include "Publisher.h"

PubNode_s *PubHead = {
    .event = NULL,
    .data = NULL,
    .next = NULL,
};
