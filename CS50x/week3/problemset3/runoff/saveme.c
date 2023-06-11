 //needs to be set up before can test main program
    for (int k = 0, l = candidate_count; k < l; k++)
    {
        if (candidates[k].eliminated == true)
        {
            continue;
        }
        else if (candidates[k].votes > min)
        {
            break;
        }
        else if (candidates[k].votes == min)
        return true;
    // TODO
    }