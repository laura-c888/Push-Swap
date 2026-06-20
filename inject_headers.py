import os
import glob

header_template = """/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   {filename:<43}   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
"""

for filepath in glob.glob('/home/lchehbi/PUSH-SWAP/src/*.c'):
    with open(filepath, 'r') as f:
        content = f.read()
    
    if "/* ************************************************************************** */" not in content[:100]:
        filename = os.path.basename(filepath)
        header = header_template.format(filename=filename)
        with open(filepath, 'w') as f:
            f.write(header + "\n" + content)

print("Headers added.")
