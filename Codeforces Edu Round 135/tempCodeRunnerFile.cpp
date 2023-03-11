do
		{			
			int32_t temp = 0;
			for(auto &v : check)
			{
				if (temp >= v)
					temp = 0;
				else
					temp += v;
			}
			if (temp > ans)
			{
				ans = temp;
				res = check;
			}
		}
		while(next_permutation(check.begin(), check.end()));